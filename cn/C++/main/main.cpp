#include "question/1436_Destination_City.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[[\\\"London\\\",\\\"New York\\\"],[\\\"New York\\\",\\\"Lima\\\"],[\\\"Lima\\\",\\\"Sao Paulo\\\"]]\"],[\"[[\\\"B\\\",\\\"C\\\"],[\\\"D\\\",\\\"B\\\"],[\\\"C\\\",\\\"A\\\"]]\"],[\"[[\\\"A\\\",\\\"Z\\\"]]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<vector<string>> arg0 = parseStringArrArr(args[0]);
      string result=s->destCity(arg0);
      string resultabc =serializeString(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}