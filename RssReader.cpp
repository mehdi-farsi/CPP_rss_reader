#include	<iostream>
#include	"RssReader.hh"

RssReader::RssReader(const char *filename)
{
  _document = new TiXmlDocument(filename);
  _handle = new TiXmlHandle(_document);


  if (!_document->LoadFile())
    {
      std::cout << "error N°" << _document->ErrorId() << ": "
		<< _document->ErrorDesc() << std::endl;
      exit(1);
    }
  if (_handle == NULL)
    {
      std::cout << "Unable to access this node !" << std::endl;
      exit(1);
    }
}

int		RssReader::dump_items()
{
  TiXmlElement	*current_node = 
    this->_handle->FirstChildElement("rss").FirstChildElement("channel").Element();

  if (current_node == NULL)
    {
      std::cout << "No item !" << std::endl;
      return (EXIT_FAILURE);
    }

  std::cout << "\033[2J\033[1;1H";
  this->dump_channel_header(current_node);

  current_node = this->_handle->FirstChildElement("rss").FirstChildElement("channel")
    .FirstChildElement("item").Element();

  if (current_node == NULL)
    {
      std::cout << "No item !" << std::endl;
      return (EXIT_FAILURE);
    }
  for (; current_node; (current_node = current_node->NextSiblingElement()))
    {
      if (current_node->NoChildren() == false)
	{
	  this->dump_item(current_node);
	}
    }
  return (EXIT_SUCCESS);
}

void		RssReader::dump_channel_header(TiXmlElement const *channel)
{
  std::string	sep(40, '*');

  dump_content_tag(channel, "title");
  dump_content_tag(channel, "description");
  dump_content_tag(channel, "lastBuildDate");
  dump_content_tag(channel, "link");
  std::cout << sep << std::endl << std::endl;
}

void		RssReader::dump_item(TiXmlElement const *item)
{
  std::string	sep(40, '-');

  dump_content_tag(item, "title");
  dump_content_tag(item, "description");
  dump_content_tag(item, "pubDate");
  dump_content_tag(item, "link");
  std::cout << sep << std::endl << std::endl;
}

void		RssReader::dump_content_tag(TiXmlElement const *node,
					    std::string const &elem)
{
    if (node->FirstChildElement(elem) != NULL)
    {
      std::cout << node->FirstChildElement(elem)->GetText() << std::endl;
    }
}
