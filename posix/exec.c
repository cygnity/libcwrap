/*
 Copyright 2018 Aaron Liu <dexin@informedia.net.cn>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>

static int
__exec(int (*exec_func)(const char *cmd, char * const argv[]),
    const char *cmd, char * const argv[], int *result)
{
  int ret = 0;
  pid_t childpid;

  if ((childpid = fork()) == -1) {
    // fork error
    error(EXIT_FAILURE, errno, "fork failed");
  } else if (childpid == 0) {
    //
    // child
    //

    if (exec_func(cmd, argv) == -1) {
      // exec error
      kill(getpid(), errno);
      // => parent response signal (errno)
    }
  } else {
    //
    // parent
    //

    pid_t child;
    int status;

    while ((child = wait(&status)) == -1 && errno == EINTR)
      ;

    if (child == -1) {
      // wait error
      error(EXIT_FAILURE, errno, "wait failed");
    } else if (!status) {
      // cmd(exec) called success

      ret = 0;
      errno = 0;
      if (result)
        *result = EXIT_SUCCESS;
    } else if (WIFEXITED(status)) {
      // cmd(exec) called failure

      ret = 0;
      errno = 0;
      if (result)
        *result = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
      // parent response signal from child

      ret = -1;
      errno = WTERMSIG(status);
    }
  }

  return ret;
}

int
Execv(const char *path, char * const argv[], int *result)
{
  return __exec(execv, path, argv, result);
}

int
Execvp(const char *file, char * const argv[], int *result)
{
  return __exec(execvp, file, argv, result);
}
