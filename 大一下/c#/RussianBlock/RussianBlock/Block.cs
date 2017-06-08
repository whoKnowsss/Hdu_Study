using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Collections;

namespace RussianBlock
{
    class Game
    {
        private int iSize = 20;
        private static int iWidth = 11;
        private static int iHeight = 20;
        private int iOffset = 50;

        private int[,] pos;
        public Point CurPoint,oriPoint,endPoint;

        public Game()
        {
            pos = new int[iWidth, iHeight];
            getRandomBlock();
        }
        public void Draw(System.Drawing.Graphics g,bool Redraw)
        {
            if (true)
            {
                g.Clear(System.Drawing.Color.Gray);
                for (int i = 0; i < iWidth; i++)
                    for (int j = 0; j < iHeight; j++)
                    {
                        g.DrawRectangle(new System.Drawing.Pen(Color.Black), i * iSize + iOffset, j * iSize + iOffset, iSize, iSize);
                        if (pos[i, j] == 1)
                            g.FillRectangle(new SolidBrush(Color.Red), i * iSize + iOffset, j * iSize + iOffset, iSize, iSize);
                        if (pos[i, j] == 99)
                            g.FillRectangle(new SolidBrush(Color.Blue), i * iSize + iOffset, j * iSize + iOffset, iSize, iSize);
                        if (pos[i, j] == -1)
                            g.FillRectangle(new SolidBrush(Color.Green), i * iSize + iOffset, j * iSize + iOffset, iSize, iSize);
                    }
            }
            else
            {
                if (pos[oriPoint.X, oriPoint.Y] == 99)
                    g.FillRectangle(new SolidBrush(Color.Blue), oriPoint.X * iSize + iOffset, oriPoint.Y * iSize + iOffset, iSize, iSize);
                else if (pos[oriPoint.X, oriPoint.Y] == -1)
                    g.FillRectangle(new SolidBrush(Color.Green), oriPoint.X * iSize + iOffset, oriPoint.Y * iSize + iOffset, iSize, iSize);
                else
                    g.FillRectangle(new SolidBrush(Color.Gray), oriPoint.X * iSize + iOffset, oriPoint.Y * iSize + iOffset, iSize, iSize);
                
                g.DrawRectangle(new System.Drawing.Pen(Color.Black), oriPoint.X * iSize + iOffset, oriPoint.Y * iSize + iOffset, iSize, iSize);
                g.FillRectangle(new SolidBrush(Color.Red), CurPoint.X * iSize + iOffset, CurPoint.Y* iSize + iOffset, iSize, iSize);
            }
        }
        public ArrayList FindPath()
        {
            
            ArrayList alPath = new ArrayList();
            FillFlag(CurPoint, endPoint);
            getPath(alPath, CurPoint);
            return alPath;

        }
        public void setFlag(Point cp, int level,ArrayList al)
        {
            if (cp.X - 1 >= 0 && pos[cp.X - 1, cp.Y] == 0)
            {
                al.Add(new Point(cp.X - 1, cp.Y));
                pos[cp.X - 1, cp.Y] = level;
            }
            if (cp.X + 1 < iWidth && pos[cp.X + 1, cp.Y] == 0)
            {
                al.Add(new Point(cp.X + 1, cp.Y));
                pos[cp.X + 1, cp.Y] = level;
            }
            if (cp.Y - 1 >= 0 && pos[cp.X, cp.Y - 1] == 0)
            {
                al.Add(new Point(cp.X, cp.Y - 1));
                pos[cp.X, cp.Y - 1] = level;
            }
            if (cp.Y + 1 < iHeight && pos[cp.X, cp.Y + 1] == 0)
            {
                al.Add(new Point(cp.X, cp.Y + 1));
                pos[cp.X, cp.Y + 1] = level;
            }
        }
        public void FillFlag(Point p1, Point p2)
        {
            ArrayList al = new ArrayList();
            ArrayList tmp = new ArrayList();
            Point cp = p2;
            int level = 2;
            setFlag(p2, level, al);
            while (al.Count>0)
            { 
                level++;
                tmp.Clear();
                for (int k = al.Count - 1; k >= 0; k--)
                {
                    setFlag((Point)al[k], level, tmp);
                    al.RemoveAt(k);
                }
                if (tmp.Count > 0)
                    al.AddRange(tmp);
                else
                   break;
            }
            
        }
        private void getPath(ArrayList al,Point p)
        {
            ArrayList tmp = new ArrayList();
            int imin = 100;
            if (p.X - 1 >= 0 && pos[p.X - 1, p.Y] > 1)
            {
                tmp.Add(new Point(p.X - 1, p.Y));
                imin = pos[p.X - 1, p.Y] < imin ? pos[p.X - 1, p.Y] : imin;
            }
            if (p.X + 1 < iWidth && pos[p.X + 1, p.Y] > 1)
            {
                tmp.Add(new Point(p.X + 1, p.Y));
                imin = pos[p.X + 1, p.Y] < imin ? pos[p.X + 1, p.Y] : imin;
            }
            if (p.Y - 1 >= 0 && pos[p.X, p.Y - 1] > 1)
            {
                tmp.Add(new Point(p.X, p.Y - 1));
                imin = pos[p.X, p.Y - 1] < imin ? pos[p.X , p.Y- 1] : imin;
            }
            if (p.Y + 1 < iHeight && pos[p.X, p.Y + 1] > 1)
            {
                tmp.Add(new Point(p.X, p.Y + 1));
                imin = pos[p.X, p.Y + 1] < imin ? pos[p.X, p.Y + 1] : imin;
            }

            if (imin == 0 || imin==100) return;
            for(int i=0;i<tmp.Count;i++)
                if(pos[((Point)tmp[i]).X,((Point)tmp[i]).Y]>1 && imin ==pos[((Point)tmp[i]).X,((Point)tmp[i]).Y])
                {
                    Point cp = (Point)tmp[i];
                    al.Add(cp);

                    if (pos[cp.X, cp.Y] == 2) return;
                    break;
                }
            
            getPath(al,(Point) al[al.Count-1]);
        }
        public void setBlock(Random r,ArrayList al,int count, int flag)
        {
            
            for (int i = 0; i < count; i++)
            {
                int index =r.Next(al.Count);
                int rn = int.Parse(al[index].ToString());
                al.RemoveAt(index);
                int x = rn % iWidth;
                int y = rn / iHeight;
                if (pos[x, y] == 0)
                    pos[x, y] = flag;
                if (flag == 1)
                {
                    CurPoint.X = x;
                    CurPoint.Y = y;
                }
                if(flag==99)
                {
                    endPoint.X = x;
                    endPoint.Y = y;

                }
            }
        }
        public void getRandomBlock()
        {           
            ArrayList al = new ArrayList();
            for (int i = 0; i < (iWidth*iHeight); i++)
                al.Add(i.ToString());
            Random r = new Random(DateTime.Now.Millisecond);
            setBlock(r,al, 1, 1);
            setBlock(r,al, 1, 99);
            setBlock(r,al, 20, -1);
        }
        public void ClearPath()
        { 
            for(int i=0;i<iWidth;i++)
                for (int j = 0; j < iHeight; j++)
                {
                    if (pos[i, j] != -1)
                        pos[i, j] = 0;
                }
            pos[CurPoint.X, CurPoint.Y] = 1;
            pos[endPoint.X, endPoint.Y] = 99;
        }
        public void PointMove(Point p, Graphics g)
        {
            oriPoint = CurPoint;
            pos[CurPoint.X, CurPoint.Y] = 0;
            CurPoint = p;
            pos[CurPoint.X, CurPoint.Y] = 1;
            Draw(g, false);
        }
        public void CurPointMove(int action,Graphics g)
        {
            oriPoint = CurPoint;
            switch (action)
            {
                case 1:
                    {
                        if (CurPoint.X > 0 && pos[CurPoint.X-1,CurPoint.Y]==0) CurPoint.X -= 1;
                        break;
                    }
                case 2:
                    {
                        if (CurPoint.Y > 0 && pos[CurPoint.X , CurPoint.Y- 1] == 0) CurPoint.Y -= 1;
                        break;
                    }
                case 3:
                    {
                        if (CurPoint.X < iWidth - 1 && pos[CurPoint.X + 1, CurPoint.Y] == 0) CurPoint.X += 1;
                        break;
                    }
                case 4:
                    {
                        if (CurPoint.Y < iHeight - 1 && pos[CurPoint.X , CurPoint.Y+1] == 0) CurPoint.Y += 1;
                        break;
                    }
            }
            pos[oriPoint.X, oriPoint.Y] = 0;
            Draw(g,false);
        }
    }
    class Block
    {
        private int[,] pos = new int[11, 20];
        public Block()
        { 
            
        }
    }

}
