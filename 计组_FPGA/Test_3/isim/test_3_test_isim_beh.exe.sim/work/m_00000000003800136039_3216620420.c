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
static const char *ng0 = "D:/programing/FPGA/Test_3/test_3.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {3U, 0U};
static unsigned int ng4[] = {1543U, 0U};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {2147483648U, 0U};
static unsigned int ng7[] = {2147483647U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {4294967295U, 0U};
static unsigned int ng10[] = {5U, 0U};
static unsigned int ng11[] = {6U, 0U};
static unsigned int ng12[] = {7U, 0U};
static unsigned int ng13[] = {305419896U, 0U};
static unsigned int ng14[] = {858989090U, 0U};
static unsigned int ng15[] = {2596069104U, 0U};
static unsigned int ng16[] = {286335522U, 0U};
static int ng17[] = {1, 0};
static int ng18[] = {0, 0};



static void Always_32_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 3328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 4392);
    *((int *)t2) = 1;
    t3 = (t0 + 3360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng0);

LAB5:    xsi_set_current_line(34, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB21;

LAB22:
LAB24:
LAB23:    xsi_set_current_line(43, ng0);

LAB34:    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB25:    goto LAB2;

LAB7:    xsi_set_current_line(35, ng0);

LAB26:    xsi_set_current_line(35, ng0);
    t7 = ((char*)((ng1)));
    t8 = (t0 + 1768);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB9:    xsi_set_current_line(36, ng0);

LAB27:    xsi_set_current_line(36, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB11:    xsi_set_current_line(37, ng0);

LAB28:    xsi_set_current_line(37, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB13:    xsi_set_current_line(38, ng0);

LAB29:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB15:    xsi_set_current_line(39, ng0);

LAB30:    xsi_set_current_line(39, ng0);
    t3 = ((char*)((ng9)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB17:    xsi_set_current_line(40, ng0);

LAB31:    xsi_set_current_line(40, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB19:    xsi_set_current_line(41, ng0);

LAB32:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng9)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB21:    xsi_set_current_line(42, ng0);

LAB33:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

}

static void Always_46_1(char *t0)
{
    char t13[8];
    char t46[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;

LAB0:    t1 = (t0 + 3576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 4408);
    *((int *)t2) = 1;
    t3 = (t0 + 3608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(47, ng0);

LAB5:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB21;

LAB22:
LAB24:
LAB23:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);

LAB25:    goto LAB2;

LAB7:    xsi_set_current_line(49, ng0);
    t7 = (t0 + 1768);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 1928);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t12);
    t16 = (t14 & t15);
    *((unsigned int *)t13) = t16;
    t17 = (t9 + 4);
    t18 = (t12 + 4);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t17);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    *((unsigned int *)t19) = t22;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB26;

LAB27:
LAB28:    t45 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t45, t13, 0, 0, 32, 0LL);
    goto LAB25;

LAB9:    xsi_set_current_line(50, ng0);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t16 = (t14 | t15);
    *((unsigned int *)t13) = t16;
    t11 = (t7 + 4);
    t12 = (t10 + 4);
    t17 = (t13 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    *((unsigned int *)t17) = t22;
    t23 = *((unsigned int *)t17);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB29;

LAB30:
LAB31:    t27 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t27, t13, 0, 0, 32, 0LL);
    goto LAB25;

LAB11:    xsi_set_current_line(51, ng0);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    *((unsigned int *)t13) = t16;
    t11 = (t7 + 4);
    t12 = (t10 + 4);
    t17 = (t13 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    *((unsigned int *)t17) = t22;
    t23 = *((unsigned int *)t17);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB32;

LAB33:
LAB34:    t18 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t18, t13, 0, 0, 32, 0LL);
    goto LAB25;

LAB13:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    *((unsigned int *)t13) = t16;
    t11 = (t7 + 4);
    t12 = (t10 + 4);
    t17 = (t13 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    *((unsigned int *)t17) = t22;
    t23 = *((unsigned int *)t13);
    t24 = (~(t23));
    *((unsigned int *)t13) = t24;
    t25 = *((unsigned int *)t17);
    t26 = (t25 != 0);
    if (t26 == 1)
        goto LAB35;

LAB36:
LAB37:    t31 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t31 & 4294967295U);
    t18 = (t13 + 4);
    t32 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t32 & 4294967295U);
    t19 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t19, t13, 0, 0, 32, 0LL);
    goto LAB25;

LAB15:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    xsi_vlog_unsigned_add(t46, 33, t7, 32, t10, 32);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t46, 0, 0, 32, 0LL);
    t12 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t12, t46, 32, 0, 1, 0LL);
    goto LAB25;

LAB17:    xsi_set_current_line(54, ng0);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    xsi_vlog_unsigned_minus(t46, 33, t7, 32, t10, 32);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t46, 0, 0, 32, 0LL);
    t12 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t12, t46, 32, 0, 1, 0LL);
    goto LAB25;

LAB19:    xsi_set_current_line(55, ng0);

LAB38:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t13, 0, 8);
    t11 = (t7 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB40;

LAB39:    t12 = (t10 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB40;

LAB43:    if (*((unsigned int *)t7) < *((unsigned int *)t10))
        goto LAB41;

LAB42:    t18 = (t13 + 4);
    t14 = *((unsigned int *)t18);
    t15 = (~(t14));
    t16 = *((unsigned int *)t13);
    t20 = (t16 & t15);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB44;

LAB45:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);

LAB46:    goto LAB25;

LAB21:    xsi_set_current_line(56, ng0);

LAB47:    xsi_set_current_line(56, ng0);
    t3 = (t0 + 1928);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 1768);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_lshift(t13, 32, t7, 32, t10, 32);
    t11 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 32, 0LL);
    goto LAB25;

LAB26:    t25 = *((unsigned int *)t13);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t13) = (t25 | t26);
    t27 = (t9 + 4);
    t28 = (t12 + 4);
    t29 = *((unsigned int *)t9);
    t30 = (~(t29));
    t31 = *((unsigned int *)t27);
    t32 = (~(t31));
    t33 = *((unsigned int *)t12);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (~(t35));
    t37 = (t30 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t41 & t39);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & t40);
    t43 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t43 & t39);
    t44 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t44 & t40);
    goto LAB28;

LAB29:    t25 = *((unsigned int *)t13);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t13) = (t25 | t26);
    t18 = (t7 + 4);
    t19 = (t10 + 4);
    t29 = *((unsigned int *)t18);
    t30 = (~(t29));
    t31 = *((unsigned int *)t7);
    t37 = (t31 & t30);
    t32 = *((unsigned int *)t19);
    t33 = (~(t32));
    t34 = *((unsigned int *)t10);
    t38 = (t34 & t33);
    t35 = (~(t37));
    t36 = (~(t38));
    t39 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t39 & t35);
    t40 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t40 & t36);
    goto LAB31;

LAB32:    t25 = *((unsigned int *)t13);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t13) = (t25 | t26);
    goto LAB34;

LAB35:    t29 = *((unsigned int *)t13);
    t30 = *((unsigned int *)t17);
    *((unsigned int *)t13) = (t29 | t30);
    goto LAB37;

LAB40:    t17 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB42;

LAB41:    *((unsigned int *)t13) = 1;
    goto LAB42;

LAB44:    xsi_set_current_line(55, ng0);
    t19 = ((char*)((ng2)));
    t27 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t27, t19, 0, 0, 32, 0LL);
    goto LAB46;

}

static void Always_60_2(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;

LAB0:    t1 = (t0 + 3824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 4424);
    *((int *)t2) = 1;
    t3 = (t0 + 3856);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(61, ng0);

LAB5:    xsi_set_current_line(61, ng0);
    t4 = (t0 + 2248);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    if (*((unsigned int *)t6) != *((unsigned int *)t7))
        goto LAB8;

LAB6:    t9 = (t6 + 4);
    t10 = (t7 + 4);
    if (*((unsigned int *)t9) != *((unsigned int *)t10))
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB8:    t11 = (t8 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t8);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB11:    goto LAB2;

LAB9:    xsi_set_current_line(61, ng0);
    t17 = ((char*)((ng17)));
    t18 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t18, t17, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Cont_62_3(char *t0)
{
    char t8[8];
    char t17[8];
    char t34[8];
    char t43[8];
    char t60[8];
    char t69[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    char *t59;
    char *t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;

LAB0:    t1 = (t0 + 4072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2248);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t9 = (t8 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 31);
    t13 = (t12 & 1);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t10);
    t15 = (t14 >> 31);
    t16 = (t15 & 1);
    *((unsigned int *)t9) = t16;
    t18 = *((unsigned int *)t4);
    t19 = *((unsigned int *)t8);
    t20 = (t18 ^ t19);
    *((unsigned int *)t17) = t20;
    t21 = (t4 + 4);
    t22 = (t8 + 4);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t21);
    t25 = *((unsigned int *)t22);
    t26 = (t24 | t25);
    *((unsigned int *)t23) = t26;
    t27 = *((unsigned int *)t23);
    t28 = (t27 != 0);
    if (t28 == 1)
        goto LAB4;

LAB5:
LAB6:    t31 = (t0 + 1768);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    memset(t34, 0, 8);
    t35 = (t34 + 4);
    t36 = (t33 + 4);
    t37 = *((unsigned int *)t33);
    t38 = (t37 >> 31);
    t39 = (t38 & 1);
    *((unsigned int *)t34) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 >> 31);
    t42 = (t41 & 1);
    *((unsigned int *)t35) = t42;
    t44 = *((unsigned int *)t17);
    t45 = *((unsigned int *)t34);
    t46 = (t44 ^ t45);
    *((unsigned int *)t43) = t46;
    t47 = (t17 + 4);
    t48 = (t34 + 4);
    t49 = (t43 + 4);
    t50 = *((unsigned int *)t47);
    t51 = *((unsigned int *)t48);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t53 = *((unsigned int *)t49);
    t54 = (t53 != 0);
    if (t54 == 1)
        goto LAB7;

LAB8:
LAB9:    t57 = (t0 + 1928);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    memset(t60, 0, 8);
    t61 = (t60 + 4);
    t62 = (t59 + 4);
    t63 = *((unsigned int *)t59);
    t64 = (t63 >> 31);
    t65 = (t64 & 1);
    *((unsigned int *)t60) = t65;
    t66 = *((unsigned int *)t62);
    t67 = (t66 >> 31);
    t68 = (t67 & 1);
    *((unsigned int *)t61) = t68;
    t70 = *((unsigned int *)t43);
    t71 = *((unsigned int *)t60);
    t72 = (t70 ^ t71);
    *((unsigned int *)t69) = t72;
    t73 = (t43 + 4);
    t74 = (t60 + 4);
    t75 = (t69 + 4);
    t76 = *((unsigned int *)t73);
    t77 = *((unsigned int *)t74);
    t78 = (t76 | t77);
    *((unsigned int *)t75) = t78;
    t79 = *((unsigned int *)t75);
    t80 = (t79 != 0);
    if (t80 == 1)
        goto LAB10;

LAB11:
LAB12:    t83 = (t0 + 4520);
    t84 = (t83 + 56U);
    t85 = *((char **)t84);
    t86 = (t85 + 56U);
    t87 = *((char **)t86);
    memset(t87, 0, 8);
    t88 = 1U;
    t89 = t88;
    t90 = (t69 + 4);
    t91 = *((unsigned int *)t69);
    t88 = (t88 & t91);
    t92 = *((unsigned int *)t90);
    t89 = (t89 & t92);
    t93 = (t87 + 4);
    t94 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t94 | t88);
    t95 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t95 | t89);
    xsi_driver_vfirst_trans(t83, 0, 0);
    t96 = (t0 + 4440);
    *((int *)t96) = 1;

LAB1:    return;
LAB4:    t29 = *((unsigned int *)t17);
    t30 = *((unsigned int *)t23);
    *((unsigned int *)t17) = (t29 | t30);
    goto LAB6;

LAB7:    t55 = *((unsigned int *)t43);
    t56 = *((unsigned int *)t49);
    *((unsigned int *)t43) = (t55 | t56);
    goto LAB9;

LAB10:    t81 = *((unsigned int *)t69);
    t82 = *((unsigned int *)t75);
    *((unsigned int *)t69) = (t81 | t82);
    goto LAB12;

}


extern void work_m_00000000003800136039_3216620420_init()
{
	static char *pe[] = {(void *)Always_32_0,(void *)Always_46_1,(void *)Always_60_2,(void *)Cont_62_3};
	xsi_register_didat("work_m_00000000003800136039_3216620420", "isim/test_3_test_isim_beh.exe.sim/work/m_00000000003800136039_3216620420.didat");
	xsi_register_executes(pe);
}
