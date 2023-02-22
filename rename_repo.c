#include <stdlib.h>

int main(void) {
    system("git remote set-url origin https://github.com/Kodisang/Simple-shell.git");
    system("git pull");
    system("mv Simple-shell simple_shell");
    system("git add .");
    system("git commit -m 'Rename repository from Simple-shell to simple_shell'");
    system("git push");
    return (0);
}
