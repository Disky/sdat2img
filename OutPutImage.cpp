 /* -*- coding: utf-8 -*-
  * Filename	:	OutPutImage.cpp
  * Date	:	2016-08-17
  */
#include <cstdio>
#include <cstdlib>
#include <OutPutImage.hpp>
#include <TransferList.hpp>
OutPutImage::OutPutImage(TransferList &__list)
{
	this->blockcount = __list.GetMax();
}
void OutPutImage::Initializer(FILE *Image_fp)
{
	fseek(Image_fp,blockcount * this->blocksize - 1,SEEK_SET);
	fputc(0,Image_fp);
	fseek(Image_fp,0,SEEK_SET);
}
void OutPutImage::ConvertDatToExt4(const TransferList& __list,FILE *DatFp,FILE *ImageFp)
{
	int end = 0,begin = 0,size = 0;
	for(unsigned index = 0;index < __list.new_cmd.size();)
	{
		begin = __list.new_cmd[index++];
		end = __list.new_cmd[index];
		size = end - begin;
		char *buf = (char*)malloc(this->blocksize * size);
		fread(buf,this->blocksize,size,DatFp);
		fseek(ImageFp,begin * this->blocksize,SEEK_SET);
		fwrite(buf,this->blocksize,size,ImageFp);
		free(buf);
	}
}
