#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"


int read_choice(int *result);
int read_line(char buffer[], int capacity);

int remove_first_name(Contact contacts[], int *count, const char *target);
int add_name(Contact contacts[], int *count, int capacity, const char *name, const char *phone);
int rename_at(Contact contacts[], int count, int index, const char *new_name);

int rename_at(Contact contacts[], int count, int index, const char *new_name) {
    if (index < 0 || index > count - 1) {
        return 0;
    }
    if (new_name[0] == '\0') {
        printf("姓名不能为空\n");
        return 0;
    } else {
        strcpy(contacts[index].name, new_name);
        return 1;
    }
}

int add_name(Contact contacts[], int *count, int capacity, const char *name, const char *phone) {
    if (*count >= capacity) {
        return 0;
    }
    if (name[0] == '\0') {
        printf("姓名不能为空\n");
        return 0;
    } else if (phone[0] == '\0') {
        printf("电话不能为空\n");
        return 0;
    } else {
        strcpy(contacts[*count].name, name);
        strcpy(contacts[*count].phone, phone);
        (*count)++;  
        return 1;        
    }
}
int remove_first_name(Contact contacts[], int *count, const char *target) {
    int index = find_first_name(contacts, *count, target);

    if (index == -1) {
        return 0;
    }

    for (int j = index; j < (*count) - 1; j++) {
        contacts[j] = contacts[j + 1];
    }
    (*count)--;
    return 1;
}

int read_line(char buffer[], int capacity) {
    if (fgets(buffer, capacity, stdin) == NULL) {
        return 0;
    }
    int found_newline = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            found_newline = 1;
        }
    }
    if (!found_newline) {
        int ch = getchar();
        if (ch == EOF && ferror(stdin)) {
            printf("读取失败\n");
            return 0;
        }
        if (ch != '\n' && ch != EOF) {
            do {
                ch = getchar();
            } while (ch != '\n' && ch != EOF);

            printf("输入太长\n");
            return -1;
        }
    }
    return 1;
}

int read_choice(int *result) {

    while (1) {
    
        char line[32];
    
        int read_result = read_line(line, sizeof line);

        if (read_result == 0) {
            return 0;
        } else if (read_result == -1) {
            continue;
        } else {
            // printf("[%s]\n", line);
        
            char *end;
            long choice = strtol(line, &end, 10);
        
            if (end == line || *end != '\0' || choice < 1 || choice > 5) {
                printf("输入无效\n");
            } else {
                // printf("%ld\n", choice);
                *result = (int)choice;
                break;
            }
        }  
    }
    return 1;
}

int main(void)
{
    Contact contacts[3];
    int count = 0;
    int capacity = (int)(sizeof contacts / sizeof contacts[0]);

    int is_loaded = load_contacts(contacts, capacity, &count, "contacts.txt");
    if (!is_loaded) {
        printf("恢复失败\n");
        return 1;
    }

    while (1) {
        puts("1. 新增");
        puts("2. 查找");
        puts("3. 删除");
        puts("4. 修改");
        puts("5. 退出");

        int selected;
        if (!read_choice(&selected)) {
            break;
        }

        if (selected == 1) {
            if (count == capacity) {
                    printf("通讯录已满\n");
                    continue;
            }

            printf("输入姓名：\n");

            char name[32];
            int read_result = read_line(name, sizeof name);

            if (read_result == 0) {
                break;
            }

            if (read_result == -1) {
                continue;
            }

            printf("输入电话：\n");
            char phone[32];
            read_result = read_line(phone, sizeof phone);

            if (read_result == 0) {
                break;
            }

            if (read_result == -1) {
                continue;
            }

            int is_added = add_name(contacts, &count, capacity, name, phone);

            if (is_added) {
                printf("已输入姓名：%s\n", name);
                printf("已输入电话：%s\n", phone);
            }

        } else if (selected == 2) {
            printf("执行查找\n");
            printf("输入查找姓名：\n");
            char target[32];
            int read_result = read_line(target, sizeof target);

            if (read_result == 0) {
                break;
            }

            if (read_result == -1) {
                continue;
            }

            int is_searched = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(contacts[i].name, target) == 0) {
                    printf("找到：%s\n", contacts[i].name);
                    printf("找到：%s\n", contacts[i].phone);
                    is_searched = 1;
                }
            }
            if (!is_searched) {
                printf("未找到\n");
            }
        } else if (selected == 3) {
            printf("输入删除姓名：\n");
            char target[32];
            int read_result = read_line(target, sizeof target);

            if (read_result == 0) {
                break;
            }

            if (read_result == -1) {
                continue;
            }

            int is_removed = remove_first_name(contacts, &count, target);

            if (!is_removed) {
                printf("未找到\n");
                continue;
            }

            printf("删除成功\n");

        } else if (selected == 4) {
            printf("输入旧姓名：");
            char old_name[32];
            int read_result = read_line(old_name, sizeof old_name);

            if (read_result == 0) {
                break;
            }

            if (read_result == -1) {
                continue;
            }

            int index = find_first_name(contacts, count, old_name);

            if (index == -1) {
                printf("未找到\n");
                continue;
            }

            printf("输入新姓名：");
            char new_name[32];
            read_result = read_line(new_name, sizeof new_name);

            if (read_result == 0) {
                break;
            }

            if (read_result == -1) {
                continue;
            }

            int is_renamed = rename_at(contacts, count, index, new_name);

            if (is_renamed) {
                printf("修改成功\n");
            }

        } else if (selected == 5) {
            
            int is_writed = save_contacts(contacts, count, "contacts.txt");
            if (is_writed) {
                printf("保存成功\n");
            } else {
                printf("保存失败\n");
            }
            printf("退出程序\n");
            break;
        }      
    }

    return 0;
}