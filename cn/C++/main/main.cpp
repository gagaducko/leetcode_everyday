#include "question/____01_09_String_Rotation_LCCI.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"\\\"abcd\\\"\",\"\\\"acdb\\\"\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      string arg0 = parseString(args[0]);
      string arg1 = parseString(args[1]);
      bool result=s->isFlipedString(arg0,arg1);
      string resultabc =serializeBool(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}