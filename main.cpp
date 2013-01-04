#include	<iostream>
#include	"RssReader.hh"

int		main(int ac, char **av)
{
  if (ac != 2)
    {
      std::cout << "Usage: " << av[0] << " XML_FILE_NAME" << std::endl;
      return (EXIT_FAILURE);
    }

  RssReader	rss(av[1]);

  return (rss.dump_items());
}
