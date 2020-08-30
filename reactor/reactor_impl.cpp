#include <map>
#include <stdio.h>
#include "event.h"
#include "event_handle.h"
#include "event_demultiplexer.h"

#include "epoll_demultiplexer.h"

#include "reactor_impl.h"

ReactorImplementation::ReactorImplementation()
{
       demultiplexer = new EpollDemultiplexer();
}

ReactorImplementation::~ReactorImplementation()
{
    if ( demultiplexer )
        delete demultiplexer;
}

int ReactorImplementation::regist( EventHandler* handler, Event evt )
{
    printf("reregist event\n");
    return demultiplexer->regist( handler, evt ); 
}

void ReactorImplementation::remove( EventHandler* handler )
{
    printf("remove event\n");
    int handle = handler->get_handle();
    demultiplexer->remove( handle );
}

void ReactorImplementation::event_loop( int timeout )
{
    printf("wait reactor event\n");
    demultiplexer->wait_event( handlers, timeout );
}

