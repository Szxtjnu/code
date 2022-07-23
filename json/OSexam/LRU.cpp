int lru_missing_page_num(int *page_seq, int seq_len, int mem_page_num)
{
	int missing_page_num = 0;
	int memory[10];			 //内存存储页面
	int page_num_in_mem = 0; //存入内存的页面数
	int i, j, k;
	//初始内存赋初值 -1
	for (i = 0; i < 10; i++)
	{
		memory[i] = -1;
	}
	for (i = 0; i < seq_len; i++)
	{
		for (j = 0; j < mem_page_num; j++)
		{
			if (memory[j] == -1) //内存i下标空间未存入页面，为空
			{
				memory[j] = page_seq[i];
				missing_page_num++;
				page_num_in_mem++;
				break;
			}
			else
			{
				if (memory[j] == page_seq[i]) //内存j不标空间已存入页面，且与当前待访问页面相同
				{
					if (((j + 1 < mem_page_num) && memory[j + 1] == -1) || j == mem_page_num - 1) // 内存j下标内是当前时间之前最后
					{
						break;
					}
					else //内存j下标不是当前时间之前最后一次访问的页面，需要调整页面顺序
					{
						for (k = j + 1; k < page_num_in_mem; k++)
						{ //将j之后的页面依次往前覆盖
							memory[k - 1] = memory[k];
						}
						memory[page_num_in_mem - 1] = page_seq[i];
					}
				}
				else //内存j下标已存入页面，且不与当前待访问页面相同
				{
					if (j == mem_page_num - 1) // 如果内存空间已满，淘汰内存0下标页面，@下标始终是最近最久未被访问的页
					{
						missing_page_num++;
						for (k = 0; k < page_num_in_mem; k++) //将0之后的页面依次往前覆盖
							memory[k] = memory[k + 1];
						memory[mem_page_num - 1] = page_seq[i];
					}
				}
			}
		}
	}

	return missing_page_num;
}
