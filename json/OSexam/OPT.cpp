int opt_missing_page_num(int* page_seq, int seq_len, int mem_page_num){
    int i, j, k;
    int l;
    int memory[10];
    bool pages_exist[10];
    // int replacedPage[10];
    // int replacedPage_index = 0;
    int page_num_in_mem = 0;
    int missing_page_num = 0;
    for(i = 0; i < seq_len; i++){
        for( j = 0; j < page_num_in_mem; j++){
            if(memory[j] == page_seq[i])
                break;
        }
        if((j == page_num_in_mem) && (page_num_in_mem < mem_page_num)){
            memory[i] = page_seq[i];
            page_num_in_mem++;
            missing_page_num++;
        }else if(j == page_num_in_mem){
            for(j = 0; j < mem_page_num; j++){
                pages_exist[j] = false;
            }
            l = 0;
            for(j=i+1; j < seq_len; j++){
                for(k = 0; k < mem_page_num; k++){
                    if(page_seq[j] == memory[k]){
                        pages_exist[k] = true;
                        l++;
                        break;
                    }
                }
                if(l==(mem_page_num-1))
                    break;
            }
            for( j = 0; j < mem_page_num; j++){
                if(pages_exist[j] == false){
                    missing_page_num++;
                    // replacedPage[replacedPage_index] = memory[j];
                    // replacedPage_index++;
                    memory[j] = page_seq[i];
                    break;
                }
            }
        }
    }
    return missing_page_num;
}