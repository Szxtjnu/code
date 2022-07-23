#include <iostream>
using namespace std;

int queye[19];
int fifo_missing_page_num(int* page_seq, int seq_len, int mem_page_num)
{
    int i, j, k, k2;
    int mempages[10][2];
    int page_num_in_mem;
    int missing_page_num;
    // int replacedPage;
    page_num_in_mem = 0;
    missing_page_num = 0;
    for( i = 0; i < seq_len; i++){
        for ( j = 0; j < page_num_in_mem; j++)
        {   
            if(mempages[j][0] == page_seq[i])
                break;
        }
        if((j == page_num_in_mem) && (page_num_in_mem < mem_page_num)){
            mempages[page_num_in_mem][0] = page_seq[i];
            mempages[page_num_in_mem][1] = i + 1;
            queye[missing_page_num] = page_seq[i];
            page_num_in_mem++;
            missing_page_num++;
        }else if(j == page_num_in_mem){
            int minv;
            minv = mempages[0][1]; k2 = 0;
            for(k = 1; k < page_num_in_mem; k++){
                if(minv > mempages[k][1]){
                    k2 = k;
                    minv = mempages[k][1];
                }
            }
            // replacedPage = mempages[k2][0];
            queye[missing_page_num] = page_seq[i];
            mempages[k2][0] = page_seq[i];
            mempages[k2][1] = i + 1;
            missing_page_num ++;
        }
    }
    // float queyelv;
    // queyelv = ((float)missing_page_num/(float)seq_len)*100;
    return missing_page_num;
}

int main(){
    int mem_page_num = 3;
    int seq_len = 17;
    int page_seq[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1};
    int result = fifo_missing_page_num(page_seq,seq_len,mem_page_num);
    // cout << result << "  " << endl;
    // cout << (float)(result)/(float)(seq_len)*100 << endl;
    for (int i = 0; i < 19; i++)
    {
        cout << queye[i] << " ";
    }
    
    return 0;

}