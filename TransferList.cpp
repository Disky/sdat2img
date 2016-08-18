 /* -*- coding: utf-8 -*-
  * Filename	:	TransferList.cpp
  * Date	:	2016-08-16
  */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <TransferList.hpp>
TransferList::TransferList(FILE *__fp)
{
	Initializer(__fp);
}
void TransferList::Initializer(FILE *__transfer_fp)
{
	char buf[255] = {0};
	this->version = atoi(fgets(buf,sizeof(buf),__transfer_fp));
	this->count = atoi(fgets(buf,sizeof(buf),__transfer_fp));
	while(fgets(buf,sizeof(buf),__transfer_fp))
	{
		if(!strncmp(buf,erase_prefix,strlen(erase_prefix)))
			this->erase_cmd = split(strstr(buf," ") + 1,',');
		else if(!strncmp(buf,new_prefix,strlen(new_prefix)))
			this->new_cmd = split(strstr(buf," ") + 1,',');
		else if(!strncmp(buf,zero_prefix,strlen(zero_prefix)))
			this->zero_cmd = split(strstr(buf," ") + 1,',');
	}
}
std::vector<int> TransferList::split(char *__src,const char __deim)
{
	std::vector<int> temp;
	std::string str(__src);
	unsigned begin = 0,end = 0;
	for(;(end = str.find_first_of(__deim,begin)) != std::string::npos;)
	{
		temp.push_back(atoi(str.substr(begin,end - begin).c_str()));
		begin = end + 1;
	}
	temp.push_back(atoi(str.substr(begin).c_str()));
	return temp;
}
int TransferList::GetMax()
{
	int v1 = *std::max_element(this->erase_cmd.begin(),this->erase_cmd.end());
	int v2 = *std::max_element(this->new_cmd.begin(),this->new_cmd.end());
	int v3 = *std::max_element(this->zero_cmd.begin(),this->zero_cmd.end());
	int max = std::max({v1,v2,v3});
	return max;
}
