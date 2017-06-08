using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace testClass
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Person p = new Person();
            Student s = new Student();
            Student s1 = new Student("10002");
            Console.Write("input your name:");
            s1.name = Console.ReadLine();
            Console.Write("input your weight(KG):");
            s1.Weight = float.Parse(Console.ReadLine());
            Console.WriteLine("hello " + s1.name + ",your weight is " + s1.Weight + "KG.");
        }
    }
}
