#include "question/3164_Find_the_Number_of_Good_Pairs_II.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1,3,4]\",\"[1,3,4]\",\"1\"],[\"[1,2,4,12]\",\"[2,4]\",\"3\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      vector<int> arg1 = parseIntegerArr(args[1]);
      int arg2 = parseInteger(args[2]);
      int result=s->numberOfPairs(arg0,arg1,arg2);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}