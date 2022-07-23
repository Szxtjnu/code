#include<bits/stdc++.h>
using namespace std;

int lru_missing_page_num(int *page_seq, int seq_len, int mem_page_num){
    int missing_page_num = 0;
    int memory[10];
    int page_num_in_mem = 0;
    int replacedPage[20];
    int replacedPage_index = 0;
    for (int i = 0; i < 10; i++)
    {
        memory[i] = -1;
    }
    for (int i = 0; i < seq_len; i++)
    {
        for (int j = 0; j < mem_page_num; j++)
        {
            if(memory[j] == -1){
                memory[j] = page_seq[i];
                missing_page_num++;
                page_num_in_mem++;
                break;
            }else{
                if(memory[i] == page_seq[i]){
                    if((j+1 < mem_page_num) && memory[j+1] == -1 || j == mem_page_num - 1)
                        break;
                    else{
                        for (int k = j+1; k < page_num_in_mem; k++)
                        {   
                            memory[k-1] = memory[k];
                        }
                        memory[page_num_in_mem-1] = page_seq[i];
                        
                    }
                
                }else{
                    if(j==mem_page_num - 1){
                        missing_page_num++;
                        replacedPage[replacedPage_index] = memory[0];
                        replacedPage_index++;
                        for (int k = 0; k < page_num_in_mem; k++)
                        {
                            memory[k] = memory[k+1];
                        }
                        memory[mem_page_num - 1] = page_seq[i];
                        
                    }
                }
            }
        }
        
    }
    cout << "±»ÌÔÌ­Ò³ÒÀ´ÎÊÇ£º ";
    for (int i = 0; i < replacedPage_index; i++)
    {
        cout << "  " << replacedPage[i];
    }
    return missing_page_num;
}

int main(){
    int a[17] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1};
    int mem_page_num = 3;
    int seq_len = 17;
    int result = lru_missing_page_num(a,mem_page_num,seq_len);
    cout << result << endl;
    return 0;
}


