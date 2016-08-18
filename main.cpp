 /* -*- coding: utf-8 -*-
  * Filename	:	main.cpp
  * Date	:	2016-08-16
  */
#include <TransferList.hpp>
#include <OutPutImage.hpp>
#include <cstdio>
int main(int argc,char **argv)
{
	if(argc != 4)
		return fprintf(stderr,"Usage:\n \
				%s <system.transfer.list> <system.new.dat> <system.new.img>\n",argv[0]);
	FILE *SystemTransferList = fopen(argv[1],"r");
	FILE *SystemNewDat = fopen(argv[2],"rb");
	FILE *SystemOutPutImage = fopen(argv[3],"wb");
	if(!SystemTransferList){
		remove(argv[3]);
		return fprintf(stderr,"%s open failure!\n",argv[1]);
	} else if(!SystemNewDat){
		remove(argv[3]);
		fclose(SystemTransferList);
		return fprintf(stderr,"%s open failure!\n",argv[2]);
	} else if(!SystemOutPutImage){
		fclose(SystemTransferList);
		fclose(SystemNewDat);
		return fprintf(stderr,"%s open failure!\n",argv[3]);
	}
	TransferList List(SystemTransferList);
	OutPutImage Image(List);
	Image.Initializer(SystemOutPutImage);
	Image.ConvertDatToExt4(List,SystemNewDat,SystemOutPutImage);
	fclose(SystemTransferList);
	fclose(SystemNewDat);
	fclose(SystemOutPutImage);
	return 0;
}
