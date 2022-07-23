#include<bits/stdc++.h>
using namespace std;
int toNextPageLen[50];

void OPT(int page_access[], int PBC, int PAC, int result[][50]){
    int k = 0;
    int nextPageAccessIndex[50];
    memset(nextPageAccessIndex, 0, sizeof(nextPageAccessIndex));
    for(int i = PAC - 1; i >= 0; i--){
        int nextIndex = nextPageAccessIndex[page_access[i]];
        if(nextIndex <= 0){
            toNextPageLen[i] = INT_MAX;
        }else{
            toNextPageLen[i] = nextIndex;
        }
        nextPageAccessIndex[page_access[i]] = i;
    }
    int flagBlock[50];
    memset(flagBlock,-1,sizeof(flagBlock));
    for(int i = 0; i < PAC; i++){
        int len = 0;
        int block = -1;
        if(flagBlock[page_access[i]]!=-1){
            for(int j = 0; j < k; j++){
                result[j][i] = result[j][i-1];
            }
            flagBlock[page_access[i]] = i;
            continue;
        }
        for(int j = 0; j < PBC; j++){
            if(k < PBC){
                if(j == k){
                    result[k][i] = page_access[i];
                    flagBlock[page_access[i]] = i;
                    k++;
                    result[PBC][i] = 1;
                    break;
                }else{
                    result[j][i] = result[j][i-1];
                }
            }else{
                result[j][i] = result[j][i-1];
                int s = toNextPageLen[flagBlock[result[j][i-1]]]-i;
                if(len < s){
                    block = j;
                    len = s;
                }
            }
        }
        if(block != -1){
            flagBlock[result[block][i]] = -1;
            flagBlock[page_access[i]] = i;
            result[block][i] = page_access[i];
            result[PBC][i] = 1;
        }
    }
}
int main(){
    int PBC;
    int PAC;
    int page_access[50];
    int result[50][50];
    memset(result, -1, sizeof(result));
    cout << "请输入物理块数： " ;
    cin >> PBC;
    cout << "请输入访问次数:  " ;
    cin >> PAC;
    for(int i = 0 ; i < PAC; i++){
        cout << "请输入第"<< i << "次访问的页面: ";
        cin >> page_access[i];
        cout << endl;
    }
    OPT(page_access, PBC, PAC, result);
    for(int i = 0; i < PBC; i++){
		printf("物理块%d\t\t",i+1);
		for(int j = 0; j < PAC; j++){
			if(result[i][j]!=-1&&result[PBC][j]!=-1){
				printf("%d\t",result[i][j]);
			}else{
				printf("\t");
			}
		}
		printf("\n");
	}
	int lack_page_number = 0;//缺页次数 
	printf("是否缺页\t");
	for(int i = 0; i < PAC; i++){
		printf("%c\t",result[PBC][i]==1?'Y':'N');
		if(result[PBC][i]==1)lack_page_number++;
	} 
	printf("\n"); 
	
	int exchange_numbber = lack_page_number - PBC;
	double lack_page_rate = lack_page_number/(double)PAC;
	printf("缺页次数: %d\n", lack_page_number);
	printf("置换次数: %d\n",exchange_numbber);
	printf("缺页率: %0.2lf%%\n",lack_page_rate) ;

}