 /* -*- coding: utf-8 -*-
  * Filename	:	OutPutImage.hpp
  * Date	:	2016-08-17
  */
#ifndef __OUTPUT_IMAGE_HPP
#define __OUTPUT_IMAGE_HPP
#include <cstdio>
#include <TransferList.hpp>
//class:OutPutImage
//用于处理新生成的img
class OutPutImage{
	int blocksize = 4096;
	int bufsize = 1024;
	int blockcount = 0;
	public:
	OutPutImage(TransferList&);
	void Initializer(FILE *);
	void ConvertDatToExt4(const TransferList&,FILE*,FILE*);
};
#endif //__OUTPUT_IMAGE_HPP
