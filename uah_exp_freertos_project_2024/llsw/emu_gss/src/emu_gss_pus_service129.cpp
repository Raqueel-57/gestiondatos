/*
 * emu_gss_pus_service129.cpp
 *
 *  Created on: Jun 3, 2024
 *      Author: atcsol
 */



#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service129.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_129_1_APPDATA_LENGTH 8
#define TC_129_2_APPDATA_LENGTH 8


EmuGSS_TCProgram129_1::EmuGSS_TCProgram129_1(uint32_t uniTime2YK,
                         const char * brief,
						 float CVx,float CVy)
                        :EmuGSS_TCProgram(uniTime2YK,129,1,
                        		TC_129_1_APPDATA_LENGTH,brief){

	mCVx=CVx;
	mCVy=CVy;

    NewProgram(this);
}
void EmuGSS_TCProgram129_1::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextFloat(mCVx);
	SetNextFloat(mCVy);



}

EmuGSS_TCProgram129_2::EmuGSS_TCProgram129_2(uint32_t uniTime2YK,
                         const char * brief,
						 float Kpx,float Kpy)
                        :EmuGSS_TCProgram(uniTime2YK,129,2,
                        		TC_129_2_APPDATA_LENGTH,brief){

	mKpx=Kpx;
	mKpy=Kpy;
    NewProgram(this);
}
void EmuGSS_TCProgram129_2::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextFloat(mKpx);
	SetNextFloat(mKpy);


}

/*
void EmuGSS_ShowServ20TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ20TMHandler serv20TMHandler(pTMDescriptor->p_tm_bytes);
	serv20TMHandler.ShowTM();

}



GSSServ20TMHandler::GSSServ20TMHandler(const uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ20TMHandler::ShowTM(){

	switch (mDFHeader.subtype) {
	case (2):
		ShowTM_20_2();
		break;

	}
}

void GSSServ20TMHandler::ShowTM_20_2(){

	uint16_t pid= GetNextUInt16AppDataField();
	uint16_t pid_value= GetNextUInt16AppDataField();

	printf(" PID %d value = %d \n",pid,pid_value);


}
*/

