#include <stdlib.h>
#include <stdio.h>

char cmd[130];
int x, y,i,m;
int main(){
	printf("密码位数:");
	scanf("%d", &x);
	printf("\n至少需要的符号数量:");
	scanf("%d", &y);
	printf("\n需要产生的密码数量:");
	scanf("%d", &m);
	printf("\n正在生成密码. . .\n");
	sprintf(cmd,"powershell \"$Assembly = Add-Type -AssemblyName System.Web; [System.Web.Security.Membership]::GeneratePassword(%d, %d)\" > pw.txt",x,y);
	system(cmd);
	if (m <= 0) { m = 1; }
	for (i = 1; i < m; i++) {
		sprintf(cmd, "powershell \"$Assembly = Add-Type -AssemblyName System.Web; [System.Web.Security.Membership]::GeneratePassword(%d, %d)\" >> pw.txt", x, y);
		system(cmd);
	}
	system("notepad pw.txt");
	return 0;
}