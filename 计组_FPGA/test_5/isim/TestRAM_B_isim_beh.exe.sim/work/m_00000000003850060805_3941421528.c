/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Night/CO/job5/TestRAM_B.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {131075U, 0U};
static unsigned int ng7[] = {132611U, 0U};
static unsigned int ng8[] = {305419896U, 0U};
static unsigned int ng9[] = {4294967295U, 0U};



static void Always_36_0(char *t0)
{
    char t6[8];
    char t20[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    int t19;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;

LAB0:    t1 = (t0 + 1812U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 2008);
    *((int *)t2) = 1;
    t3 = (t0 + 1840);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(37, ng0);

LAB5:    xsi_set_current_line(38, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1196);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1288);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t2) == 0)
        goto LAB6;

LAB8:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;

LAB9:    t5 = (t6 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (~(t12));
    t14 = *((unsigned int *)t6);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(50, ng0);

LAB24:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);

LAB25:    t2 = ((char*)((ng2)));
    t19 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t19 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng3)));
    t19 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t19 == 1)
        goto LAB28;

LAB29:    t2 = ((char*)((ng4)));
    t19 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t19 == 1)
        goto LAB30;

LAB31:    t2 = ((char*)((ng5)));
    t19 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t19 == 1)
        goto LAB32;

LAB33:
LAB34:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(41, ng0);

LAB13:    xsi_set_current_line(42, ng0);
    t17 = (t0 + 692U);
    t18 = *((char **)t17);

LAB14:    t17 = ((char*)((ng2)));
    t19 = xsi_vlog_unsigned_case_compare(t18, 2, t17, 2);
    if (t19 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng3)));
    t19 = xsi_vlog_unsigned_case_compare(t18, 2, t2, 2);
    if (t19 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng4)));
    t19 = xsi_vlog_unsigned_case_compare(t18, 2, t2, 2);
    if (t19 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng5)));
    t19 = xsi_vlog_unsigned_case_compare(t18, 2, t2, 2);
    if (t19 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB12;

LAB15:    xsi_set_current_line(43, ng0);
    t21 = (t0 + 968U);
    t22 = *((char **)t21);
    memset(t20, 0, 8);
    t21 = (t20 + 4);
    t23 = (t22 + 4);
    t24 = *((unsigned int *)t22);
    t25 = (t24 >> 0);
    *((unsigned int *)t20) = t25;
    t26 = *((unsigned int *)t23);
    t27 = (t26 >> 0);
    *((unsigned int *)t21) = t27;
    t28 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t28 & 255U);
    t29 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t29 & 255U);
    t30 = (t0 + 1196);
    xsi_vlogvar_assign_value(t30, t20, 0, 0, 8);
    goto LAB23;

LAB17:    xsi_set_current_line(44, ng0);
    t3 = (t0 + 968U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t6 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 8);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 8);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 255U);
    t17 = (t0 + 1196);
    xsi_vlogvar_assign_value(t17, t6, 0, 0, 8);
    goto LAB23;

LAB19:    xsi_set_current_line(45, ng0);
    t3 = (t0 + 968U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t6 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 16);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 16);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 255U);
    t17 = (t0 + 1196);
    xsi_vlogvar_assign_value(t17, t6, 0, 0, 8);
    goto LAB23;

LAB21:    xsi_set_current_line(46, ng0);
    t3 = (t0 + 968U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t6 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 24);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 24);
    *((unsigned int *)t3) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t12 & 255U);
    t17 = (t0 + 1196);
    xsi_vlogvar_assign_value(t17, t6, 0, 0, 8);
    goto LAB23;

LAB26:    xsi_set_current_line(52, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 1288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    goto LAB34;

LAB28:    xsi_set_current_line(53, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 1288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    goto LAB34;

LAB30:    xsi_set_current_line(54, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 1288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    goto LAB34;

LAB32:    xsi_set_current_line(55, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 1288);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    goto LAB34;

}


extern void work_m_00000000003850060805_3941421528_init()
{
	static char *pe[] = {(void *)Always_36_0};
	xsi_register_didat("work_m_00000000003850060805_3941421528", "isim/TestRAM_B_isim_beh.exe.sim/work/m_00000000003850060805_3941421528.didat");
	xsi_register_executes(pe);
}
