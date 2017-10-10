#include "anyoption/anyoption.h"

void get_commandline_options( int argc, char* argv[] );

int main( int argc, char* argv[] )
{
        get_commandline_options( argc, argv );
        return 0;
}

void get_commandline_options( int argc, char* argv[] )
{
    AnyOption *opt = new AnyOption();
    opt->addUsage( "" );
    opt->addUsage( "Usage: " );
    opt->addUsage( "" );
    opt->addUsage( " -?  --help             Prints this help " );
    opt->addUsage( " -h  --height <number>  Output Image Height " );
    opt->addUsage( " -w  --width <number>   Output Image Width " );
    opt->addUsage( "" );

    opt->setFlag( "help", '?' );
    opt->setOption( "width", 'w' );
    opt->setOption( "height", 'h' );

    /* for options that will be checked only from the option/resource file */
    opt->setFileOption(  "title" ); /* an option (takes an argument), supporting only long form */

    /* 5. PROCESS THE COMMANDLINE AND RESOURCE FILE */

    /* read options from a file with ':' separated opttions or flags, one per line */
    opt->processFile( "glisten.conf" );

    /* go through the command line and get the options  */
    opt->processCommandArgs( argc, argv );

    if( ! opt->hasOptions()) { /* print usage if no options */
                opt->printUsage();
            delete opt;
        return;
    }

    if( opt->getFlag( "help" ) || opt->getFlag( 'h' ) )
        opt->printUsage();

    if( opt->getValue( 'w' ) != NULL  || opt->getValue( "width" ) != NULL  )
            cout << "width = " << opt->getValue( 'w' ) << endl ;

    if( opt->getValue( 'h' ) != NULL  || opt->getValue( "height" ) != NULL  )
            cout << "height = " << opt->getValue( 'h' ) << endl ;


    if( opt->getValue( "name" ) != NULL )
                cout << "name = " << opt->getValue( "name" ) << endl ;
    if( opt->getValue( "title" ) != NULL )
            cout << "title = " << opt->getValue( "title" ) << endl ;
        if( opt->getFlag( 'c' ) )
        cout << "c = flag set " << endl ;
        if( opt->getFlag( 'z' ) || opt->getFlag( "zip" ) )
        cout << "zip = flag set " << endl ;
        cout << endl ;


    for( int i = 0 ; i < opt->getArgc() ; i++ )
    {
        cout << "input file: " <<  opt->getArgv( i ) << endl ;
    }

    delete opt;
}
