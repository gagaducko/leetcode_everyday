#include "question/1884_Egg_Drop_With_2_Eggs_and_N_Floors.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"2\"],[\"100\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      int arg0 = parseInteger(args[0]);
      int result=s->twoEggDrop(arg0);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}