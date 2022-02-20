# include <iostream>
# include <string>
# include <map>
# include <algorithm>

int main ()
{
    int N;
    int min = 100;
    std::string student[2];
    int exam_scores[3];
    std::map<std::string, int> result;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> student[0] >> student[1] >> exam_scores[0] >> exam_scores[1] >> exam_scores[2];
        int aver_score = (exam_scores[0] + exam_scores[1] + exam_scores[2])/3;
        auto name = []( std::string a, std::string b ) { return a + ' ' + b; };
        if (aver_score > 0)
        {
            if (aver_score < min) {
                result = {};
                result[name(student[0], student[1])] = aver_score;
                min = aver_score;
            }
            else if (aver_score == min) {
                result[name(student[0], student[1])] = aver_score;
            }
        }
    }
    std::cout << "\n";
    for_each(result.begin(), result.end(), [](std::pair<std::string, int> iter){
        std::cout << iter.first << " " << iter.second << "\n";
    });
    return (0);
}
