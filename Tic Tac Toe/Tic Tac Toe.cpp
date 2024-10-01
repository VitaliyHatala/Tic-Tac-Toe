
#include <iostream>
using namespace std;


class Point
{
public:
   int x;
   int y;

   Point() : x(0), y(0) {}

   Point(int x, int y)
   {
      this->x = x;
      this->y = y;
   }


   Point(const Point& P)
   {
      x = P.x;
      y = P.y;
   }

   friend ostream& operator<<(ostream& os, const Point& P)
   {
      os << "(" << P.x << ";" << P.y << ")";
      return os;
   }
   bool operator==(Point& P)
   {
      return x == P.x && y == P.y;
   }

   void Set_X()
   {
      cin >> x;
   }

   void Set_Y()
   {
      cin >> y;
   }

   int Get_X()
   {
      return x;
   }
   int Get_Y()
   {
      return y;
   }
};
bool CheckDesk(char** arr)
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (arr[i][j] == '-')
         {
            return false;
         }
      }
   }
   return true;
}
bool CheckWin1(char** arr, char symbol)
{

   for (int i = 0; i < 3; i++)
   {
      if (arr[i][0] == symbol && arr[i][1] == symbol && arr[i][2] == symbol)
         return true;
      if (arr[0][i] == symbol && arr[1][i] == symbol && arr[2][i] == symbol)
         return true;
   }


   if (arr[0][0] == symbol && arr[1][1] == symbol && arr[2][2] == symbol)
      return true;
   if (arr[0][2] == symbol && arr[1][1] == symbol && arr[2][0] == symbol)
      return true;

   return false;
}
bool IsDuplicateMove(Point* p[], int p_counter, int x, int y)
{
   for (int i = 0; i < p_counter; i++)
   {
      if (p[i]->Get_X() == x && p[i]->Get_Y() == y)
      {
         return true;
      }
   }
   return false;
}

int main()
{
   char** arr = new char* [3];
   for (int i = 0; i < 3; i++)
   {
      arr[i] = new char[3];
   }

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         arr[i][j] = '-';
      }
   }
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   int p_counter = 0;
   int row_first_player = 0;
   int column_first_player = 0;
   int row_second_player = 0;
   int column_second_player = 0;
   Point* p[9];


   for (int i = 0; i < 9; i++)
   {
      p[i] = new Point();
   }
   while (!CheckWin1(arr, '*') && !CheckWin1(arr, '0'))
   {
      cout << "\tFirst player moves\n";
      cout << "Enter row: ";
      p[p_counter]->Set_X();
      row_first_player = p[p_counter]->Get_X();
      cout << "Enter column: ";
      p[p_counter]->Set_Y();
      column_first_player = p[p_counter]->Get_Y();
      if (IsDuplicateMove(p, p_counter, row_first_player, column_first_player) || row_first_player < 1 || row_first_player > 3 || column_first_player < 1 || column_first_player > 3)
      {
         cout << "Wrong move, try again.\n";
         break;
      }
      else
      {
         arr[row_first_player - 1][column_first_player - 1] = '*';
         for (int i = 0; i < 3; i++)
         {
            for (int j = 0; j < 3; j++)
            {
               cout << arr[i][j] << " ";
            }
            cout << endl;
         }
      }
      if (CheckWin1(arr, '*'))
      {
         cout << "First player win";
         break;
      }

      p_counter++;
      if (p_counter >= 9) break;
      cout << "\tSecond player moves\n";
      cout << "Enter row: ";
      p[p_counter]->Set_X();
      row_second_player = p[p_counter]->Get_X();
      cout << "Enter column: ";
      p[p_counter]->Set_Y();
      column_second_player = p[p_counter]->Get_Y();
      if (IsDuplicateMove(p, p_counter, row_second_player, column_second_player) || row_second_player < 1 || row_second_player > 3 || column_second_player < 1 || column_second_player > 3)
      {
         cout << "Wrong move, try again.\n";
         break;
      }
      else
      {
         arr[row_second_player - 1][column_second_player - 1] = '0';
         for (int i = 0; i < 3; i++)
         {
            for (int j = 0; j < 3; j++)
            {
               cout << arr[i][j] << " ";
            }
            cout << endl;
         }
      }
      if (CheckWin1(arr, '0'))
      {
         cout << "Second player win";
         break;
      }


      p_counter++;
      if (p_counter >= 9) break;
   }
   if (!CheckWin1(arr, '*') && !CheckWin1(arr, '0') && CheckDesk(arr))
   {
      cout << "Draw" << endl;
   }
   return 0;
}

