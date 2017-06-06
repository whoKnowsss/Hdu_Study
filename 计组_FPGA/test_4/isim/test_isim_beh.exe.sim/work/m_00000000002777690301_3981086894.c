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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/11655/Desktop/FPGA/shiyan4/shiyan4.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static int ng6[] = {32, 0};
static int ng7[] = {1, 0};
static unsigned int ng8[] = {2147483648U, 0U};
static unsigned int ng9[] = {1543U, 0U};
static unsigned int ng10[] = {858989090U, 0U};
static unsigned int ng11[] = {2596069104U, 0U};



static void Always_32_0(char *t0)
{
    char t6[8];
    char t17[8];
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
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    int t34;

LAB0:    t1 = (t0 + 4288U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 5352);
    *((int *)t2) = 1;
    t3 = (t0 + 4320);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng0);

LAB5:    xsi_set_current_line(34, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2568);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 5);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 1688U);
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

LAB11:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(36, ng0);

LAB13:    xsi_set_current_line(37, ng0);
    t18 = (t0 + 1368U);
    t19 = *((char **)t18);
    memset(t17, 0, 8);
    t18 = (t19 + 4);
    t20 = *((unsigned int *)t18);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t18) == 0)
        goto LAB14;

LAB16:    t25 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t25) = 1;

LAB17:    t26 = (t17 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t17);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(48, ng0);

LAB32:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1848U);
    t4 = *((char **)t2);
    t2 = (t0 + 2728);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 5);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1528U);
    t4 = *((char **)t2);

LAB33:    t2 = ((char*)((ng2)));
    t34 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t34 == 1)
        goto LAB34;

LAB35:    t2 = ((char*)((ng3)));
    t34 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t34 == 1)
        goto LAB36;

LAB37:    t2 = ((char*)((ng4)));
    t34 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t34 == 1)
        goto LAB38;

LAB39:    t2 = ((char*)((ng5)));
    t34 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t34 == 1)
        goto LAB40;

LAB41:
LAB42:
LAB20:    goto LAB12;

LAB14:    *((unsigned int *)t17) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(38, ng0);

LAB21:    xsi_set_current_line(39, ng0);
    t32 = (t0 + 1848U);
    t33 = *((char **)t32);
    t32 = (t0 + 2568);
    xsi_vlogvar_assign_value(t32, t33, 0, 0, 5);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);

LAB22:    t2 = ((char*)((ng2)));
    t34 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t34 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng3)));
    t34 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t34 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng4)));
    t34 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t34 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng5)));
    t34 = xsi_vlog_unsigned_case_compare(t3, 2, t2, 2);
    if (t34 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB20;

LAB23:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t18);
    t10 = (t9 >> 0);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 255U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t6, 0, 0, 8);
    goto LAB31;

LAB25:    xsi_set_current_line(42, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 8);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t18);
    t10 = (t9 >> 8);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 255U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t6, 0, 0, 8);
    goto LAB31;

LAB27:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 16);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t18);
    t10 = (t9 >> 16);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 255U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t6, 0, 0, 8);
    goto LAB31;

LAB29:    xsi_set_current_line(44, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t18 = (t5 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 24);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t18);
    t10 = (t9 >> 24);
    *((unsigned int *)t4) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t12 & 255U);
    t19 = (t0 + 3048);
    xsi_vlogvar_assign_value(t19, t6, 0, 0, 8);
    goto LAB31;

LAB34:    xsi_set_current_line(51, ng0);
    t5 = (t0 + 2168U);
    t18 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t19 = (t18 + 4);
    t7 = *((unsigned int *)t18);
    t8 = (t7 >> 0);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t19);
    t10 = (t9 >> 0);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t12 & 255U);
    t25 = (t0 + 3048);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 8);
    goto LAB42;

LAB36:    xsi_set_current_line(52, ng0);
    t5 = (t0 + 2168U);
    t18 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t19 = (t18 + 4);
    t7 = *((unsigned int *)t18);
    t8 = (t7 >> 8);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t19);
    t10 = (t9 >> 8);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t12 & 255U);
    t25 = (t0 + 3048);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 8);
    goto LAB42;

LAB38:    xsi_set_current_line(53, ng0);
    t5 = (t0 + 2168U);
    t18 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t19 = (t18 + 4);
    t7 = *((unsigned int *)t18);
    t8 = (t7 >> 16);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t19);
    t10 = (t9 >> 16);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t12 & 255U);
    t25 = (t0 + 3048);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 8);
    goto LAB42;

LAB40:    xsi_set_current_line(54, ng0);
    t5 = (t0 + 2168U);
    t18 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t19 = (t18 + 4);
    t7 = *((unsigned int *)t18);
    t8 = (t7 >> 24);
    *((unsigned int *)t6) = t8;
    t9 = *((unsigned int *)t19);
    t10 = (t9 >> 24);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t11 & 255U);
    t12 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t12 & 255U);
    t25 = (t0 + 3048);
    xsi_vlogvar_assign_value(t25, t6, 0, 0, 8);
    goto LAB42;

}

static void Always_61_1(char *t0)
{
    char t13[8];
    char t15[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t14;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    int t28;
    char *t29;
    unsigned int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;

LAB0:    t1 = (t0 + 4536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 5368);
    *((int *)t2) = 1;
    t3 = (t0 + 4568);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(62, ng0);

LAB5:    xsi_set_current_line(63, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(69, ng0);

LAB15:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB16;

LAB17:
LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(64, ng0);

LAB9:    xsi_set_current_line(65, ng0);
    xsi_set_current_line(65, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3368);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);

LAB10:    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t13, 0, 8);
    xsi_vlog_signed_less(t13, 32, t4, 32, t5, 32);
    t11 = (t13 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (~(t6));
    t8 = *((unsigned int *)t13);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    goto LAB8;

LAB11:    xsi_set_current_line(66, ng0);
    t12 = ((char*)((ng2)));
    t14 = (t0 + 3208);
    t17 = (t0 + 3208);
    t18 = (t17 + 72U);
    t19 = *((char **)t18);
    t20 = (t0 + 3208);
    t21 = (t20 + 64U);
    t22 = *((char **)t21);
    t23 = (t0 + 3368);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    xsi_vlog_generic_convert_array_indices(t15, t16, t19, t22, 2, 1, t25, 32, 1);
    t26 = (t15 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t16 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 3368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t13, 0, 8);
    xsi_vlog_signed_add(t13, 32, t4, 32, t5, 32);
    t11 = (t0 + 3368);
    xsi_vlogvar_assign_value(t11, t13, 0, 0, 32);
    goto LAB10;

LAB13:    t33 = *((unsigned int *)t15);
    t34 = *((unsigned int *)t16);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_assign_value(t14, t12, 0, *((unsigned int *)t16), t36);
    goto LAB14;

LAB16:    xsi_set_current_line(71, ng0);

LAB19:    xsi_set_current_line(72, ng0);
    t4 = (t0 + 1528U);
    t5 = *((char **)t4);

LAB20:    t4 = ((char*)((ng2)));
    t28 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t28 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng3)));
    t28 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t28 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng4)));
    t28 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t28 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng5)));
    t28 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t28 == 1)
        goto LAB27;

LAB28:
LAB29:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t11 = (t0 + 3208);
    t12 = (t0 + 3208);
    t14 = (t12 + 72U);
    t17 = *((char **)t14);
    t18 = (t0 + 3208);
    t19 = (t18 + 64U);
    t20 = *((char **)t19);
    t21 = (t0 + 1848U);
    t22 = *((char **)t21);
    xsi_vlog_generic_convert_array_indices(t13, t15, t17, t20, 2, 1, t22, 5, 2);
    t21 = (t13 + 4);
    t6 = *((unsigned int *)t21);
    t28 = (!(t6));
    t23 = (t15 + 4);
    t7 = *((unsigned int *)t23);
    t31 = (!(t7));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB30;

LAB31:    goto LAB18;

LAB21:    xsi_set_current_line(73, ng0);
    t11 = ((char*)((ng8)));
    t12 = (t0 + 2888);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 32);
    goto LAB29;

LAB23:    xsi_set_current_line(74, ng0);
    t3 = ((char*)((ng9)));
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    goto LAB29;

LAB25:    xsi_set_current_line(75, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    goto LAB29;

LAB27:    xsi_set_current_line(76, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    goto LAB29;

LAB30:    t8 = *((unsigned int *)t13);
    t9 = *((unsigned int *)t15);
    t35 = (t8 - t9);
    t36 = (t35 + 1);
    xsi_vlogvar_assign_value(t11, t4, 0, *((unsigned int *)t15), t36);
    goto LAB31;

}

static void Cont_83_2(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 4784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 2568);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t8, t11, 2, 1, t14, 5, 2);
    t15 = (t0 + 5480);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t5, 8);
    xsi_driver_vfirst_trans(t15, 0, 31);
    t20 = (t0 + 5384);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Cont_84_3(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 5032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 3208);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 3208);
    t10 = (t9 + 64U);
    t11 = *((char **)t10);
    t12 = (t0 + 2728);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t5, 32, t4, t8, t11, 2, 1, t14, 5, 2);
    t15 = (t0 + 5544);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t5, 8);
    xsi_driver_vfirst_trans(t15, 0, 31);
    t20 = (t0 + 5400);
    *((int *)t20) = 1;

LAB1:    return;
}


extern void work_m_00000000002777690301_3981086894_init()
{
	static char *pe[] = {(void *)Always_32_0,(void *)Always_61_1,(void *)Cont_83_2,(void *)Cont_84_3};
	xsi_register_didat("work_m_00000000002777690301_3981086894", "isim/test_isim_beh.exe.sim/work/m_00000000002777690301_3981086894.didat");
	xsi_register_executes(pe);
}
