import sqlite3
from pathlib import Path


class StudentRepository:
    """负责 students 表的创建、查询、添加和删除。"""

    def __init__(self, database_path):
        self.database_path = Path(database_path)
        self.database_path.parent.mkdir(parents=True, exist_ok=True)
        self.connection = sqlite3.connect(self.database_path)
        self.create_table()

    def create_table(self):
        self.connection.execute(
            """
            CREATE TABLE IF NOT EXISTS students (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                age INTEGER NOT NULL,
                city TEXT NOT NULL
            )
            """
        )
        self.connection.commit()

    def list_students(self):
        cursor = self.connection.execute(
            "SELECT id, name, age, city FROM students ORDER BY id"
        )
        return cursor.fetchall()

    def add_student(self, name, age, city):
        cursor = self.connection.execute(
            "INSERT INTO students (name, age, city) VALUES (?, ?, ?)",
            (name, age, city),
        )
        self.connection.commit()
        return cursor.lastrowid

    def delete_student(self, student_id):
        cursor = self.connection.execute(
            "DELETE FROM students WHERE id = ?",
            (student_id,),
        )
        self.connection.commit()
        return cursor.rowcount == 1

    def close(self):
        self.connection.close()
