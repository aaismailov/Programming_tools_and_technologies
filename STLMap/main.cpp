# include <iostream>
# include <string>
# include <map>

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
        if (aver_score > 0)
        {
            if (aver_score < min) {
                result = {};
                result[student[0] + ' ' + student[1]] = aver_score;
                min = aver_score;
            }
            else if (aver_score == min) {
                result[student[0] + ' ' + student[1]] = aver_score;
            }
        }
    }
    std::cout << "\n";
    for (std::map<std::string, int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    return (0);
}
