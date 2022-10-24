int wc = wait(NULL);
				printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
				rc, wc, (int) getpid());