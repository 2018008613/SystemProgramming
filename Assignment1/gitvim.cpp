#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <regex>
#define BUFF_SIZE 1024

using namespace std;

int main(int argc, char* argv[]) {
	FILE *fp;
	char command[50] = "git ls-files `git rev-parse --show-toplevel`";
	char buff[BUFF_SIZE];
	char list[11][BUFF_SIZE];
	int cnt = 0;
	string command2 = "vim ";

	if (argc < 2) {
		printf("Input search key\n");
		exit(1);
	}

	fp = popen(command, "r");
	regex pattern(argv[1]);
	while (fgets(buff, BUFF_SIZE, fp) != NULL) {
		buff[strlen(buff) - 1] = '\0';
		string f = "";
		for (int i = 0;i < strlen(buff);i++)
		{
			if (buff[i] == '/')
				f = "";
			else
				f += buff[i];
		}

		if (cnt < 10 && regex_search(f.c_str(), pattern))
		{
			cnt++;
			strcpy(list[cnt], buff);
		}
	}
	pclose(fp);
	if (cnt == 0)
	{
		printf("There is no file\n");
		exit(1);
	}
	if (cnt == 1)
	{
		string a(list[1]);
		command2 = command2 + a;
		int ret = system(command2.c_str());
	}
	else
	{
		for (int i = 1;i <= cnt;i++)
			printf("%s\t(%d)\n", list[i], i);
		while (1)
		{
			char ch[51];
			printf("Enter file shortcut (shown on the right) or keyword to further refine the search: \n");
			scanf("%s", ch);
			int num = atoi(ch);
			if (num != 0)
			{
				string a(list[num]);
				command2 = command2 + a;
				int ret = system(command2.c_str());
				break;
			}
			int cnt2 = 0;
			regex pattern2(ch);
			for (int i = 1;i <= cnt;i++)
			{
				string f = "";
				for (int j = 0;j < strlen(list[i]);j++)
				{
					if (list[i][j] == '/')
						f = "";
					else
						f += list[i][j];
				}
				if (regex_search(f.c_str(), pattern2))
				{
					cnt2++;
					strcpy(list[cnt2], list[i]);
				}
			}
			if (cnt2 == 0)
			{
				printf("There is no file\n");
				exit(1);
			}
			else if (cnt2 == 1)
			{
				string a(list[1]);
				command2 = command2 + a;
				int ret = system(command2.c_str());
				break;
			}
			for (int i = 1;i <= cnt2;i++)
				printf("%s\t(%d)\n", list[i], i);
			cnt = cnt2;
		}
	}

	return 0;
}


