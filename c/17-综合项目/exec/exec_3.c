#include <stdio.h>

#include <stdlib.h>

int main() {

    while (1) {

        char line[32];
    
        if (fgets(line, sizeof line, stdin) == NULL) {
            printf("读取失败或输入结束\n");
            return 1;
        }
    
        printf("[%s]\n", line);
        
        int found_newline = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '\n') {
                line[i] = '\0';
                found_newline = 1;
                break;
            }
        }

        if (!found_newline) {
            int ch = getchar();
            if (ch == EOF && ferror(stdin)) {
                printf("读取失败\n");
                return 1;
            }
            if (ch != '\n' && ch != EOF) {
                do {
                    ch = getchar();
                } while (ch != '\n' && ch != EOF);

                printf("输入太长\n");
                continue;
            }
        }
    
        printf("[%s]\n", line);
    
        char *end;
        long choice = strtol(line, &end, 10);
    
        if (end == line || *end != '\0' || choice < 1 || choice > 3) {
            printf("输入无效\n");
        } else {
            printf("%ld\n", choice);
            break;
        }
    }


    return 0;
}