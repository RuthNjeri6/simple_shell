#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int command_executer(char *pathname, char *argv[]);
char *read_line(void);
void shell_loop(char *argv[]);
char **split_line(char *line);

// main function-the entry point of the this program
int main(int argc, char *argv[], char *envp[]) //gcc cmd.c -o cmd  ./cmd
{
    shell_loop(argv);
    return 0;
}


// reads commands as one string and return the pointer to that string.
char *read_line(void)
{
    char *ptr;
    char ch;
    int pos = 0;
    pos = 0;
    ptr = malloc(sizeof(char) * 1024);
    
    if(ptr == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(99);
        }

    while(1)
    {
        ch = getchar();

        if (ch == '\n' || ch == '\0')
        {
            ptr[pos] = '\0';
            return ptr;
        }
        ptr[pos] = ch;
        pos++;
    }
       
}

//splits the line read to commands returns an array of this commands
char **split_line(char *line)
{
    char **tokens;
    char *token;
    int position = 0;
    int buffsize = 1024;
    tokens = malloc(sizeof(char *) * buffsize);

    if (tokens == NULL)
    {
        perror("Malloc failure\n");
        exit(98);
    }

    token = strtok(line, " ");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;
        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}

//executes the command typed by the user
int command_executer(char *pathname, char *argv[])
{
    pid_t pid, wpid;
    int status;
    char path[1024] = "/bin/";

    strcat(path, pathname);

    pid = fork();
    if (pid == 0)
    {
        if (execve(path, argv, NULL) == -1)
        {
            printf("No such file\n");
            exit(3);
        }
    }
    else if (pid < 0)
    {
        printf("Error forking\n");
    }
    else
    {
        //parent Process
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED); //wait for the process's state to change

            //reapeates doing line 42 
            //as long as the child process has not been exited or killed by a signal
        }while (!WIFEXITED(status) && !WIFSIGNALED(status)); 

    }
    return 1;
}

// display prompt and wait for user to type in a command
//this is repeated every time s command gets executed
void shell_loop(char *argv[])
{
    char *line;
    char **args;
    int status;

    do {
        printf("#cisfun$ ");
        line = read_line();
        args = split_line(line);
        status = command_executer(args[0], args);

        free(line);
    } while (status);
}