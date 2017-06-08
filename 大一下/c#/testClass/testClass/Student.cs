using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace testClass
{
    class Person
    {
        public string name;//公有字段
        public int age;
        protected int gender;//保护字段
        private float weight;//私有字段
        public float Weight //公有属性
        {
            get { return weight; }
            set
            {
                if (value > 2 && value < 1000)
                    weight = value;
                else
                    throw new Exception("the weight data is error!");
            }
        }
        public string Eat()
        {
            return "Person is Eating.";
        }
    }
    class Student:Person
    {
        public string stuid;

        public string StuID  //属性
        {
            get;
            set;
        }
        public Student()  //默认构造函数
        {
            this.stuid = "10001";
        }
        public Student(string stuId) //带参数的非默认构造函数
        {
            this.stuid = stuId;
        }

        public string Study()
        {
            return "student is studying.";
        }


    }
    
}
