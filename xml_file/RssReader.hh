#ifndef		__RSSREADER_HH__
#define		__RSSREADER_HH__

#include	<tinyxml.h>

class		RssReader
{
private:
  TiXmlDocument	*_document;
  TiXmlHandle	*_handle;
  void		dump_item(TiXmlElement const *);
  void		dump_channel_header(TiXmlElement const *);
  void		dump_content_tag(TiXmlElement const *, std::string const &);
public:
  RssReader(const char *);
  int		dump_items();
};

#endif		/* __RSSREADER_HH__ */
