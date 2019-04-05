#include <iostream>
#include <map>
#include <random>


int
main ()
{
  std::map<int, double> m;

  std::random_device generator;
  std::uniform_int_distribution<int> intdist (0, 100);
  std::uniform_real_distribution<double> doubdist (0.0, 1.0);

  for (int ii = 0; ii < 10; ++ii)
    m[intdist (generator)] = doubdist (generator);

  std::cout << "initial contents" << std::endl;
  for (auto& jj : m)
    std::cout << jj.first << " " << jj.second << std::endl;

  bool ereased=false; // Poichè cancellato un elemento l'albero
                      // viene riorganizzato, se cancella
                      // un elemento torno a scorrere l'albero
                      // dall'inizio.
  for (auto jj = m.begin (); jj != m.end (); ++jj){
    if(ereased){
      jj = m.begin();
      ereased = false;
    }
    if (jj->second < .5){
      m.erase (jj);
      ereased = true;
    }
  }

  std::cout << '\n';
  std::cout << "final contents" << std::endl;
  for (auto& jj : m)
    std::cout << jj.first << " " << jj.second << std::endl;

}
