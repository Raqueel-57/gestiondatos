/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

#define FT_SOLO_EPD_ICU_SERV_17_0010
#define FT_SOLO_EPD_ICU_SERV_9_0020 // Para que nos diga el tiempo de a bord
#define FT_UAH_EXP_SERV_129_0010



/*#ifdef FT_SOLO_EPD_ICU_SERV_9_0020

#define FT_SOLO_EPD_ICU_SERV_9_0020_TIME 200000

EmuGSS_TCProgram9_129 prog_FT_0020_step_0(UNITIME_AFTER_POWER_ON + 10 ,
		"FT_SOLO_EPD_ICU_SERV_9_0020 step 0, Update UniTime Test",
		FT_SOLO_EPD_ICU_SERV_9_0020_TIME);



#endif */

//TODO

#ifdef FT_UAH_EXP_SERV_129_0010


EmuGSS_TCProgram129_1 prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 10,
					"FT_UAH_EXP_SERV_129_00XX step 0, Set Kp", 0.2, 0.2);

EmuGSS_TCProgram129_2 prog_FT_0011_step_0(UNITIME_AFTER_POWER_ON + 20,
					"FT_UAH_EXP_SERV_129_00XX step 0, Set Command Vx and Vy "
					, 17, 21);

#endif


