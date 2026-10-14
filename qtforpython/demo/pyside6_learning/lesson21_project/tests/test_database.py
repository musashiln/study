import unittest

from database import StudentRepository


class StudentRepositoryTests(unittest.TestCase):
    def setUp(self):
        # :memory: 表示数据库只存在内存中，测试结束后自动消失。
        self.repository = StudentRepository(":memory:")

    def tearDown(self):
        self.repository.close()

    def test_add_and_list_students(self):
        student_id = self.repository.add_student("小明", 18, "北京")
        students = self.repository.list_students()

        self.assertEqual(student_id, 1)
        self.assertEqual(students, [(1, "小明", 18, "北京")])

    def test_delete_student(self):
        student_id = self.repository.add_student("小红", 20, "上海")

        deleted = self.repository.delete_student(student_id)

        self.assertTrue(deleted)
        self.assertEqual(self.repository.list_students(), [])
