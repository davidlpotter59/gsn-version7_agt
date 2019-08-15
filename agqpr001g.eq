/* agqpr001g.eq

   scips.com

   June 26, 2012

   to track what reports the agents are running and when
*/

description tracking of reports that the agents run ;

include "startend.inc"

where agqreport:run_date >= l_starting_date and
      agqreport:run_date <= l_ending_date
list
/domain="agqreport"
/nobanner
/nopageheadings

agqreport:agent_no
sfsagent:name[1]
agqreport:report_name
agqreport:run_date
agqreport:run_time

sorted by agent_no/newline=2
          report_name/newline=2
          run_date
          run_time

 

