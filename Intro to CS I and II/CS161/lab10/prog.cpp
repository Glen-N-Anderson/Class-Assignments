#include "netflix.hpp"
int main() {
        netflix movie;
        set_netflix_info(&movie);
        std::cout << "Name: " << movie.name << std::endl;
        std::cout << "Rating: " << movie.rating << std::endl;
        return 0;
}

