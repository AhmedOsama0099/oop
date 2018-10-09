#include <iostream>
#include<bits/stdc++.h>
#include <cassert>

using namespace std;
/*
                                -----------------       ----------
                                | struct matrix |       | main() |
                                -----------------       ----------


  |operator+|   |operator-|   |operator*|   |operator+scalar|   |operator-scalar|   |operator*scalar|   |operator+=|   |operator-=|   |operator+=scalar|   |operator-=scalar|   |operator++|   |operator--|   |operator>>|   |operator<<|   |operator==|   |operator!=|   |isSquare()|   |isSymmetric()|   |isIdentity()|   |transpose()|



*/


struct matrix
{
    int* data;
    int row, col;
    bool   isSquare   (matrix mat);
    bool   isSymetric (matrix mat);
    bool   isIdentity (matrix mat);

};

    matrix operator+  (matrix mat1,matrix mat2)
    {
        assert((mat1.row == mat2.row) && (mat1.col == mat2.col));
        matrix mat3;
        mat3.row=mat1.row;
        mat3.col=mat1.col;
        mat3.data = new int [mat1.row * mat1.col];
        for (int i = 0; i < mat1.row*mat1.col; i++)
        {
            mat3.data[i]=mat1.data[i]+mat2.data[i];
        }
        return mat3;
    }

    matrix operator-  (matrix mat1,matrix mat2)
    {
        assert((mat1.row == mat2.row) && (mat1.col == mat2.col));
        matrix mat4;
        mat4.row=mat1.row;
        mat4.col=mat1.col;
        mat4.data = new int [mat1.row * mat1.col];

        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat4.data[i]=mat1.data[i]-mat2.data[i];
        }
        return mat4;
    }
    matrix operator*  (matrix mat1,matrix mat2)
    {
        assert((mat1.col == mat2.row));
        matrix mat4;
        mat4.row=mat1.row;
        mat4.col=mat2.col;
        mat4.data = new int [mat1.row * mat2.col];
        for(int i=0; i<mat4.row*mat4.col; i++)
            mat4.data[i]=0;
        int count1=0,count2=0,count3=0,count4=0,count5=0,check1=0,check2=0;
        while(count5<mat4.row*mat4.col) //size mat 4
        {
            //count3 =count2 to jump over mat 2
            //count1 =count3 to jump over mat 1
            for(int j=0; j<mat1.col; j++) // 23mdt 1
            {
                mat4.data[count5]+=mat1.data[count1]*mat2.data[count2];
                count1++;
                count2+=mat2.col;// 23mdt mat 2

            }
            /*. . .  0. .1
              . . .  2. .3
                     4. .5*/
            check1++;
            count3++;
            if (check1==mat2.col) // col mat 2 to start again in mat 2
            {
                count3=0;
                check1=0;
            }
            count2=count3;
            check2++;
            if (check2%mat2.col==0) // col mat2 to jump to the next row in mat 1
            {
                count4+=mat1.col; //col mat 1

            }
            count1=count4;
            count5++;

        }
        return mat4;
    }

    matrix operator+  (matrix mat1,int scalar)
    {
        matrix mat4;
        mat4.row=mat1.row;
        mat4.col=mat1.col;
        mat4.data = new int [mat1.row * mat1.col];

        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat4.data[i]=mat1.data[i]+scalar;
        }
        return mat4;
    }
    matrix operator-  (matrix mat1,int scalar)
    {
        matrix mat4;
        mat4.row=mat1.row;
        mat4.col=mat1.col;
        mat4.data = new int [mat1.row * mat1.col];
        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat4.data[i]=mat1.data[i]-scalar;
        }
        return mat4;
    }

    matrix operator* (matrix mat1,int scalar)
    {
        matrix mat4;
        mat4.row=mat1.row;
        mat4.col=mat1.col;
        mat4.data = new int [mat1.row * mat1.col];
        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat4.data[i]=mat1.data[i]*scalar;

        }
        return mat4;
    }


//20170047


    matrix operator+= (matrix mat1,matrix mat2)
    {
        assert((mat1.row == mat2.row) && (mat1.col == mat2.col));
        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat1.data[i]=mat1.data[i]+mat2.data[i];

        }
        return mat1;
    }

    matrix operator-= (matrix mat1,matrix mat2)
    {
        assert((mat1.row == mat2.row) && (mat1.col == mat2.col));
        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat1.data[i]=mat1.data[i]-mat2.data[i];

        }
        return mat1;
    }

    matrix operator+= (matrix mat1,int scalar)
    {

        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat1.data[i]=mat1.data[i]+scalar;
        }
        return mat1;
    }


    matrix operator-= (matrix mat1,int scalar)
    {

        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat1.data[i]=mat1.data[i]-scalar;

        }
        return mat1;
    }

    void operator++ (matrix mat1)
    {

        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat1.data[i]=mat1.data[i]+1;
        }
    }
    void operator-- (matrix mat1)
    {

        for (int i = 0; i < mat1.row*mat1.col; i++)
        {

            mat1.data[i]=mat1.data[i]-1;
        }
    }

    istream& operator >> (istream& in, matrix & mat)
    {
        cout<<"Enter col and row: ";
        in>>mat.row>>mat.col;
        cout<<"Enter ur matrix: ";
        for (int i = 0; i < mat.row*mat.col; i++)
        {

            in>>mat.data[i];
        }
        return in;
    }

//20170019

     ostream& operator<< (ostream& out, matrix mat)
    {
        for (int i = 0; i < mat.row*mat.col; i++)
        {
            if(i%mat.col==0)
            {
                cout<<endl;
            }
            out<<mat.data[i]<<" ";

        }
        return out;
    }

    bool   operator== ( matrix mat1,matrix mat2)
    {
        for(int i=0; i<mat1.row*mat1.col; i++)
        {
            if(mat1.data[i]==mat2.data[i])
                return true;
            else
                return false;
        }
    }
    bool   operator!= ( matrix mat1,matrix mat2)
    {
        for(int i=0; i<mat1.row*mat1.col; i++)
        {
            if(mat1.data[i]!=mat2.data[i])
                return true;
            else
                return false;
        }
    }

    bool   isSquare   (matrix mat1)
    {
        if(mat1.row== mat1.col)
            return true;
        else
            return false;
    }


    bool   isSymetric (matrix mat1)
    {
        if(mat1.row==mat1.col)
        {
            matrix mat4;
            mat4.col=mat1.row;
            mat4.row=mat1.col;
            mat4.data = new int [mat1.row * mat1.col];
            int u=0,temp=0,p=0,i=0,o=0;

            while (u<mat1.col)
            {
                u;
                for(i=u ; i<mat1.col*mat1.row; i+=mat1.col)
                {
                    mat4.data[p]=mat1.data[i];
                    p++;
                }
                u++;
            }
            for(i=0; i<mat1.row*mat1.col; i++)
            {
                if(mat1.data[i]!=mat4.data[i])o++;
            }
            if(o==0)
                return true;
            else
                return false;
        }


        else
            return false;
    }

    bool isidentity (matrix mat1)
    {
        if(mat1.row== mat1.col)
        {
            int c=0,b=0;
            for(int i=0; i<mat1.row*mat1.col; i+=mat1.col+1)
            {
                if(mat1.data[i]!=1)c++;

            }
            for(int i=0; i<mat1.row*mat1.col; i++)
            {
                if (i%(mat1.col+1)==0)continue;

                else if(mat1.data[i]!=0)b++;
            }
            if (c==0 && b==0)return true;
            else return false;
        }
        else
            return false;

    }

    matrix transpose (matrix mat1)
    {
        matrix mat4;
        mat4.col=mat1.row;
        mat4.row=mat1.col;
        mat4.data = new int [mat1.row * mat1.col];
        int u=0,temp=0,p=0,i=0;

        while (u<mat1.col)
        {
            u;
            for(i=u ; i<mat1.col*mat1.row; i+=mat1.col)
            {
                mat4.data[p]=mat1.data[i];
                p++;
            }
            u++;
        }

        return mat4;
    }






void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}




int main()
{
  int scalar;
  int data1 [] = {10,20,30,40,50,60};
  int data2 [] = {1,2,3,4};
  int data3 [] = {5,2,3,4,5,6};
  int data4 [] = {10,20,30,40,50,60};
  int data5 [] = {10,20,30,40,50,60};
  int data6 [] = {1,0,0,0,1,0,0,0,1};
  matrix mat1, mat2, mat3 ,mat4,mat5,mat6, mat10;
  createMatrix (2, 3 ,data1, mat1);
  createMatrix (3, 2, data2, mat2);
  createMatrix (2, 3, data3, mat3);
  createMatrix (2, 3, data4, mat4);
  createMatrix (2, 3, data5, mat5);
  createMatrix (3, 3, data6, mat6);
/*
cin>>mat1>>mat3;
*/
  cout<<"mat1 = "<<endl<<mat1<<endl<<endl;
  cout<<"mat2 = "<<endl<<mat2<<endl<<endl;
  cout<<"mat3 = "<<endl<<mat3<<endl<<endl;

  cout<<"20170010\n \n";

  cout<<"mat1+mat3 = "<<endl<<(mat1+mat3)<<endl<<endl;
  cout<<"mat3+mat3 = "<<endl<<(mat3+mat3)<<endl<<endl;
  cout<<"mat1-mat3 = "<<endl<<(mat1-mat3)<<endl<<endl;
  cout<<"mat1*mat2 = "<<endl<<(mat1*mat2)<<endl<<endl;
  cout<<"mat1+5 = "<<endl<<(mat1+5)<<endl<<endl<<endl;
  cout<<"mat1-5 = "<<endl<<(mat1-5)<<endl<<endl<<endl;
  cout<<"mat1*5 = "<<endl<<(mat1*5)<<endl<<endl<<endl;



  //20170047

  cout<<"20170047 \n \n";

  cout<<"mat1+=mat3 = "<<endl<<(mat1+=mat3)<<endl<<endl;
  cout<<"mat1-=mat3 = "<<endl<<(mat1-=mat3)<<endl<<endl;
  cout<<"mat1+=10 = "<<endl<<(mat1+=10)<<endl<<endl;
  cout<<"mat1-=10 = "<<endl<<(mat1-=10)<<endl<<endl;
  ++mat1;
  cout<<"++mat1 = "<<endl<<mat1<<endl<<endl;
  --mat1;
  cout<<"--mat1 = "<<endl<<mat1<<endl<<endl;
  /*cin>>mat1;
  cout<<mat1;*/
  cout<<endl;

  /*cout<<"Enter the Scalar: ";
  cin>>scalar;
  cout<<"mat1+scalar = "<<endl<<(mat1+scalar)<<endl<<endl<<endl;
  cout<<"mat1-scalar = "<<endl<<(mat1-scalar)<<endl<<endl<<endl;
  cout<<"mat1*scalar = "<<endl<<(mat1*scalar)<<endl<<endl<<endl;
  cout<<"mat1+=scalar = "<<endl<<(mat1+=scalar)<<endl<<endl;
  cout<<"mat1-=scalar = "<<endl<<(mat1-=scalar)<<endl<<endl;*/



//20170019

  cout<<"20170019 \n \n";

  cout<<"Is mat4==mat5 ? = "<<(mat4==mat5)<<endl<<endl;
  cout<<"Is mat1==mat3 ? = "<<(mat1==mat3)<<endl<<endl;
  cout<<"Is mat1!=mat3 ? = "<<(mat1!=mat3)<<endl<<endl;
  cout<<"Is mat4!=mat5 ? = "<<(mat4!=mat5)<<endl<<endl;
  cout<<"Is mat6 Square ? = "<<(isSquare(mat6))<<endl<<endl;
  cout<<"Is mat1 Square ? = "<<(isSquare(mat1))<<endl<<endl;
  cout<<"Is mat6 Symmetric ? = "<<(isSymetric(mat6))<<endl<<endl;
  cout<<"Is mat1 Symmetric ? = "<<(isSymetric(mat1))<<endl<<endl;
  cout<<"Is mat6 Identity ? = "<<(isidentity(mat6))<<endl<<endl;
  cout<<"Is mat1 Identity ? = "<<(isidentity(mat1))<<endl<<endl;
  cout<<"The transpose for mat1 == "<<endl<<transpose(mat1)<<endl<<endl;

    return 0;
}
