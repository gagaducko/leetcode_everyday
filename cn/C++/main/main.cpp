#include "question/3192_Minimum_Operations_to_Make_Binary_Array_Elements_Equal_to_One_II.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[0,1,1,0,1]\"],[\"[1,0,0,0]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      int result=s->minOperations(arg0);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}