 /* -*- coding: utf-8 -*-
  * Filename	:	TransferList.hpp
  * Date	:	2016-08-16
  */
#ifndef __TRANSFER_LISR_HPP
#define __TRANSFER_LISR_HPP
#include <cstdio>
#include <vector>
//class:TransferList
//用于处理system.transfer.list
class TransferList{
	public:
	int version = 1;
	int count = 0;
	std::vector<int> erase_cmd = {0};
	std::vector<int> new_cmd = {0};
	std::vector<int> zero_cmd = {0};
	const char *erase_prefix = "erase";
	const char *zero_prefix = "zero";
	const char *new_prefix = "new";
	TransferList(FILE *);
	void Initializer(FILE *);
	int GetMax();
	std::vector<int> split(char*,const char);
};
#endif
