/* agqpr9104.eq

   November 20, 2000 

   SCIPS.com, Inc.

   quote worksheet for MSO agq
*/ 

DEFINE STRING I_NAME[50] = agqpersonal:business_name[1]

DEFINE STRING
        I_REV_NAME[50] =
        TRUN(I_NAME[(POS("=",I_NAME)+1),
        LEN(I_NAME)])+" "+TRUN(I_NAME[0,(POS("=",I_NAME)-1)])

Define signed ascii number l_amount = 0 ;

define string l_company_name = sfscompany:name[1]
  
define file alt_agqmaster = access agqmaster, set
                            agqmaster:app_no = agqpersonal:app_no, exact

define file alt_agqlocation = access agqlocation, set
                              agqlocation:app_no = agqpersonal:app_no,
                              agqlocation:prem_no = agqpersonal:prem_no,
                              agqlocation:build_no = agqpersonal:build_no, generic
                                                    
define file alt_agqend = access agqend, set
                         agqend:app_no = agqpersonal:app_no, 
                         agqend:prem_no = agqpersonal:prem_no,
                         agqend:build_no = agqpersonal:build_no, one to many,
 generic

define file alt_agqsupp = access agqsupp, set
                          agqsupp:app_no = agqpersonal:app_no, 
                          agqsupp:prem_no = agqpersonal:prem_no,
                          agqsupp:build_no = agqpersonal:build_no, one to 
MANY, generic

define file alt_sfsagent = access sfsagent, set
                           sfsagent:company_id = agqpersonal:company_id,
                           sfsagent:agent_no = agqpersonal:agent_no, generic

define file alt_sfspayortype = access sfspayortype, set
                               sfspayortype:company_id = agqpersonal:company_id,
                               sfspayortype:payor_code = alt_agqsupp:mortgage_type_1, generic

define file alt_sfsmorttype = access sfsmorttype, set
                              sfsmorttype:company_id = agqpersonal:company_id,
                              sfsmorttype:mortgage_code = alt_agqsupp:mortgage_type_2, generic
     
define file alt_sfsmort = access sfsmort, set
                          sfsmort:company_id = agqpersonal:company_id,
                          sfsmort:mortgage_id = alt_agqsupp:mortgage_id, generic

define string l_mortgage = if agqsupp:mortgage_id = "" then
                               trun(alt_agqsupp:name[1]) +  " " +
                               trun(alt_agqsupp:address[1]) +  " " +
                               trun(alt_agqsupp:city) + " " +
                               ", " + trun(alt_agqsupp:str_state) + " " +
                               trun(alt_agqsupp:str_zipcode)

define string l_mort = if agqsupp:mortgage_id <> "" then
                           trun(alt_sfsmort:name[1]) + " " +
                           trun(alt_sfsmort:address[1]) + " " +
                           trun(alt_sfsmort:city) + " " +
                           ", " + trun(alt_sfsmort:str_state) + " " +
                           trun(alt_sfsmort:str_zipcode)

define file alt_sfsstate = access sfsstate, set
                           sfsstate:company_id = agqpersonal:company_id ,
                           sfsstate:state = agqpersonal:state,
                           sfsstate:county= 000, generic

define file alt1_sfsstate = access sfsstate, set
                            sfsstate:company_id = agqpersonal:company_id,
                            sfsstate:state = agqpersonal:state,
                            sfsstate:county = agqpersonal:county, generic

define file alt_sfsline = access sfsline, set
                          sfsline:company_id = agqpersonal:company_id,
                          sfsline:line_of_business = agqpersonal:line_of_business,
                          sfsline:lob_subline = "00", generic
    
define unsigned ascii number l_form[2] = agqpersonal:form

define file alt_sfsform = access sfsform, set
                          sfsform:company_id = agqpersonal:company_id,
                          sfsform:state = agqpersonal:state,
                          sfsform:line_of_business = agqpersonal:line_of_business,
                          sfsform:policy_form = l_form, generic

define file alt_scipscontrol = access scipscontrol, 
                                  set scipscontrol:company_id = alt_sfsform:COMPANY_ID,
                                      scipscontrol:state      = alt_sfsform:state,
                                      scipscontrol:lob_code   = alt_SFSLINE:LOB_CODE, exact


define unsigned ascii number l_alarm_1 = if agqpersonal:alarm_factor[1] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[1] * 100)) 
                             l_alarm_2 = if agqpersonal:alarm_factor[2] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[2] * 100)) 
                             l_alarm_3 = if agqpersonal:alarm_factor[3] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[3] * 100)) 
                             l_alarm_4 = if agqpersonal:alarm_factor[4] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[4] * 100)) 
                             l_alarm_5 = if agqpersonal:alarm_factor[5] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[5] * 100)) 
                             l_alarm_6 = if agqpersonal:alarm_factor[6] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[6] * 100)) 
                             l_alarm_7 = if agqpersonal:alarm_factor[7] <> 0 then
                                             (100 - (agqpersonal:alarm_factor[7] * 100))
  
                             l_alarm_percent = l_alarm_1 + l_alarm_2 +
                                               l_alarm_3 + l_alarm_4 +
                                               l_alarm_5 + l_alarm_6 +
                                               l_alarm_7

where agqpersonal:app_no = agqprint1:app_no

LIST
/NOPAGEHEADINGS
/NOBANNER
/NOTOTALS
/NOBLANKLINES
/DOMAIN="agqpersonal"
/INLINE
/NOHEADIngs
/duplicates
/pagelength=0

box/noblanklines/noheadings/noduplicates/column=1
"LOCATION:   "/COLUMN=30
agqpersonal:PREM_NO/MASK="ZZZ9"/NEWLINE/column=42
"BUILDING:       "/COLUMN=30 
agqpersonal:BUILD_NO/MASK="ZZZ9"/NEWLINE=2/column=42/duplicates

"LOCATION:"/column=1                                
if alt_agqlocation:app_no = agqprint1:app_no then
    {
    trun(alt_agqlocation:address) + " " + trun(alt_agqlocation:CITY) + ", " +
    trun(alt_agqlocation:str_state) + " " + trun(alt_agqlocation:str_zipcode)/column=20/newline
    }
else
    {
    "No location has been entered"/column=20/newline/noduplicates
    }  
       
"STATE:"/COLUMN=1
alt_sfsstate:description/column=10

"COUNTY:"/COlumn=40
ALT1_sfsstate:DESCRIPTION/newline         

"TERRITORY: "/column=1
agqpersonal:TERRITORY/newline/column=21

"FORM:"/column=1
agqpersonal:form/column=23/duplicates

"DEDUCTIBLE:"/column=40
agqpersonal:deductible/newline/column=58

"WIND DEDUCTIBLE:"/column=1
agqpersonal:wind_deductible/column=20/mask="ZZZ9"

"CONSTRUCTION: "/column=40
agqpersonal:CONSTRUCTION/newline/column=62

"PROTECTION:"/COLUMN=1
agqpersonal:PROTECTION/column=22

"NO. OF FAMILIES:"/column=40
agqpersonal:no_families/newline/column=62/duplicates
 
"YR CONSTRUCTION:"/COLUMN=1
agqpersonal:year_construction/mask="ZZZ9"/column=20

"OWNER OCCUPIED:"/column=40
agqpersonal:owner_occupied/newline/column=62

"SEASONAL:"/column=1
agqpersonal:seasonal/column=23
      
"NO LOSSES:"/column=40
agqpersonal:no_claims/column=61/newline

if agqpersonal:replacement_acv = "A" then
    {
    "ACV:"/column=1
    "Y"/column=23/duplicates/newline
    }
else
    {
    ""/newline
    }
 
if agqpersonal:inflation_guard <> 0 then
    {
    "INFLATION %:"/column=1
    agqpersonal:inflation_guard/column=22
    }

box/noblanklines/noheading/column=1
if agqpersonal:ho15 <> "" then
    {
    "HO15:"/column=40
    agqpersonal:ho15/column=62/newline
    }
else
    {
    " "/newline
    }

if alt_sfsline:lob_code = "DWELLING" then
    {
    "THEFT COVERAGE:"/column=1
    switch(agqpersonal:theft)
      case 1  : "Y"
      default : "N"/column=23/duplicates
    "TIER:"/column=40
    agqpersonal:tier/column=61/newline    
    "HURRICANE DEDUCT:"/column=1
    agqpersonal:hurricane_deductible/column=18
    }
else
    {
    "TIER:"/column=1
    agqpersonal:tier/column=22  
    "HURRICANE DEDUCT:"/column=40
    agqpersonal:hurricane_deductible/column=57
    }


if agqpersonal:companion_discount = 1 and
   agqpersonal:state = 29 then
    {
    ""/newline
    "PALISADES POLICY NO: "/column=1
    agqpersonal:palisades_policy_no/column=22
    "CREDIT AMOUNT: "/column=40 
    agqpersonal:palisades_credit/column=57/mask="$ZZZZ.99-"
    }

if ((agqpersonal:companion_discount = 1 or
   agqpersonal:companion_discount_1 = 1) and
   agqpersonal:state = 19) then
    {
    ""/newline
    if agqpersonal:companion_discount = 1 then
        {
        "PROGRESSIVE POLICY NO: "/column=1
        agqpersonal:palisades_policy_no/column=22
        "CREDIT AMOUNT: "/column=40 
        agqpersonal:palisades_credit/column=57/mask="$ZZZZ.99-"
        }
    else
    if agqpersonal:companion_discount_1 = 1 then
        {
        "AGENCY INS POLICY NO: "/column=1
        agqpersonal:palisades_policy_no/column=22
        "CREDIT AMOUNT: "/column=40 
        agqpersonal:palisades_credit/column=57/mask="$ZZZZ.99-"
        }
    }

if agqpersonal:ifa_companion_discount = 1 then 
    {
    ""/newline
    "IFA POLICY NO: "/column=1
    agqpersonal:ifa_policy_no/column=22
    "CREDIT AMOUNT: "/column=40 
    agqpersonal:ifa_credit/column=57/mask="$ZZZZ.99-"
    }

if agqpersonal:other_companion_auto_credit = 1 then 
    {
    ""/newline
    agqpersonal:other_companion_co_name/column=1
    agqpersonal:other_companion_policy_no/column=22
    "CREDIT AMOUNT: "/column=40 
    agqpersonal:palisades_credit/column=57/mask="$ZZZZ.99-"
    }

if agqpersonal:state = 19 then
    {
    ""/newline
    "WINDSTORM LOSS MITIGATION CREDIT:"/column=1
    agqpersonal:windstorm_factor/mask="ZZ%"
    } 

End box/newlines=2
     
If agqmaster:total[9] <> 0 then
    {
    "SEASONAL OCCUPANCY "/newline=2
    }
  
"DWELLING:"/column=10
if agqpersonal:dwelling_limit <> 0 then
{
agqpersonal:dwelling_LIMIT/MASK="$$,$$$,$$$"/column=40
agqpersonal:dwelling_PREMIUM[1] + agqmaster:total[9] -
agqpersonal:windstorm_surcharge/MASK="$$$,$$9.99-"/newline/column=55
}

"OTHER STRUCTURES:"/column=10
agqpersonal:structures_limit[1]/mask="$$,$$$,$$$"/column=40
/duplicates
if agqpersonal:structures_premium_1[1] <> 0 then
    agqpersonal:structures_premium_1[1]/mask="$$$,$$$.99-"/newline/column=55

"PERSONAL PROPERTY:"/column=10
agqpersonal:contents_LIMIT/MASK="$$,$$$,$$9"/column=40/duplicates
if agqpersonal:contents_premium[1] <> 0 and
   agqpersonal:dwelling_premium[1] = 0 then
    box/noblanklines/noheading/column=1
    agqpersonal:contents_PREMIUM[1] + agqmaster:total[9] - agqpersonal:windstorm_surcharge/MASK="$$$,$$$.99-"/newline/column=55/duplicates 
    end box
else
if agqpersonal:contents_premium[1] <> 0 then
    box/noblanklines/noheading/column=1
    agqpersonal:contents_PREMIUM[1]/MASK="$$$,$$$.99-"/newline/column=55/duplicates 
    end box
    
""/newline
"LOSS OF USE:"/column=10
agqpersonal:loss_rents_limit/mask="$$,$$$,$$$"/column=40/duplicates
if agqpersonal:loss_rents_premium[1] <> 0 then
    agqpersonal:loss_rents_premium[1]/mask="$$$,$$$.99-"/newline/column=55
                                  
"PERSONAL LIABILITY:"/column=10             
agqpersonal:liability_limit/mask="$$,$$$,$$9"/column=40/duplicates      
agqpersonal:liab_medical_premium/mask="$$$,$$9.99-"/newline/column=55/duplicates
                    
"MEDICAL PAYMENTS:"/column=10             
agqpersonal:medical_limit/mask="$$,$$$,$$9"/column=40/newline/duplicates

if agqpersonal:df_deduct_premium <> 0 then
    {
    "DEDUCTIBLE:"/column=10
    agqpersonal:df_deduct_premium/column=55/mask="$$$,$$$.99-"/newline
    }                    
  
end box/newlines
     
followed by

box/noheadings/noblanklines 
--"LOCATION"/column=1
--"BUILDING"/COLUMN=10                  
"FORM/EDITION"/column=1
"DESCRIPTION"/column=25
"PREMIUM"/column=70
end box/newline

followed by                      

box/noblanklines/noheadings 
if alt_agqend:code = "MPL70" then
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    box/noblanklines/noheading
    alt_agqend:form_edition/duplicates/column=1
    if l_alarm_percent <> 0 then   
        box/noblanklines/noheadings/column=1
        alt_agqend:description[1,50] + str(l_alarm_percent,"ZZZZ%")/column=20/duplicates
        end box
    else    
        if (l_alarm_percent = 0 and
           (alt_sfsline:option = "P" or
           alt_sfsline:option = "R")) then 
            box/noblanklines/noheadings/column=1
            alt_agqend:description[1,50] + "  2%"/column=20/duplicates
            end box           
    "INCL"/column=75/duplicates
    end box
    }
else                  
if alt_agqend:code = "MPL76" then
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    alt_agqend:form_edition/duplicates/column=1
    alt_agqend:description[1,50]/column=20/duplicates
    "INCL"/column=75/duplicates 
    }
else                  
if alt_agqend:code = "MDW30" and
   alt_agqend:premium = 0 then
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    alt_agqend:form_edition/duplicates/column=1
    alt_agqend:description[1,50]/column=20/duplicates
    "INCL"/column=75/duplicates 
    }
else                  
if alt_agqend:code = "MPL72" then
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    alt_agqend:form_edition/duplicates/column=1
    alt_agqend:description[1,50]/column=20/duplicates
    "INCL"/column=75/duplicates 
    }
else                  
if alt_agqend:code = "MDL1" then
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    alt_agqend:form_edition/duplicates/column=1
    alt_agqend:description[1,50]/column=20/duplicates
    "INCL"/column=75/duplicates 
    }
else                  
if alt_agqend:code = "MPL22" then
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    alt_agqend:form_edition/duplicates/column=1
    alt_agqend:description[1,50]/column=20/duplicates 
    "INCL"/column=75/duplicate
    }
else
    {
--    alt_agqend:prem_no/duplicates 
--    alt_agqend:build_no/duplicates/column=9 
    alt_agqend:form_edition/duplicates/column=1
    alt_agqend:description[1,50]/column=20/duplicates
    alt_agqend:premium/mask="ZZ,ZZZ.99-"/duplicates/column=70
    if alt_agqend:minimum_premium = "Y" then
        "M.P."/column=85/duplicates
    }

end box/newline

followed by

if agqpersonal:secondary_residence_premium <> 0 then
    {
    " "/newline=2
    "SECONDARY RESIDENCE:"/column=1
    agqpersonal:secondary_residence_premium/column=70/mask="ZZ,ZZZ.99-"/newline
    agqpersonal:secondary_residence[1]/column=1
    agqpersonal:secondary_residence_families[1]/column=80/newline
    if agqpersonal:secondary_residence[2] <> "" then
        {
        agqpersonal:secondary_residence[2]/column=1
        agqpersonal:secondary_residence_families[2]/column=80/newline
        }
     }

followed by  

if alt_agqsupp:app_no = agqpersonal:app_no then
box/noheadings/noblanklines 
"LOCATION"/column=1
"BUILDING"/COLUMN=10                  
"ADDITIONAL INTEREST"/column=30/newline

--followed by
 
--box/noblanklines/noheadings/column=1      
alt_agqsupp:prem_no/duplicates
alt_agqsupp:build_no/duplicates/column=9
if alt_agqsupp:mortgage_id <> "" then
    box/noblanklines/noheadings/duplicates
    trun(alt_sfsmort:name[1]) + " " +
    trun(alt_sfsmort:address[1]) + " " +
    trun(alt_sfsmort:CITY) + ", " +
    trun(alt_sfsmort:str_state) + " " +
    trun(alt_sfsmort:str_ZIPCODE)
    end box
else  
    box/noblanklines/noheadings/duplicates
    trun(alt_agqsupp:NAME[1]) + " " +
    trun(alt_agqsupp:address[1]) + " " +
    trun(alt_agqsupp:CITY) + ", " +
    trun(alt_agqsupp:str_state) + " " +
    trun(alt_agqsupp:str_ZIPCODE)
    END BOx
end box/newlines
                          
followed by  
           
if agqmisc:app_no = agqpersonal:app_no then
{        
"MISCELLANEOUS"/newline=2
"DESCRIPTION"/column=18
"PREMIUM"/column=50/newline=2
agqmisc:description/column=11
agqmisc:premium/column=52/mask="ZZZZZ-"
}
  
sorted by agqpersonal:app_no/newpage 

end of report
""/newline=2
todaysdate/heading="DATE PRINTED"
username/column=40/heading="PRINTED BY"

top of report
l_company_name/column=25/newline=2

"APP NO:"/column=1
agqpersonal:app_no/noheading
     
INCLUDE "RENAEQ2.INC"/HEADING="NAME"/COLUMN=30/newline

IF agqname:name[2] <> "" THEN
    {
    agqname:name[2]/COLUMN=36/NEWLINE
    }
IF agqname:name[3] <> "" THEN
    {
    agqname:name[3]/COLUMN=36/NEWLINE
    }
IF agqname:address[1] <> "" THEN
    {
    agqname:address[1]/COLUMN=36/NEWLINE
    }
if agqname:address[2] <> "" then
    {
    agqname:address[2]/column=36/newline
    }
if agqname:address[3] <> "" then
    {
    agqname:address[3]/column=36/newline
    }
box/noblanklines/noheading
if agqname:city <> "" then
    box/noblanklines/noheadings/squeeze/column=36
    agqname:city + ","
    agqname:str_state
    agqname:str_zipcode
    end box
end box/newlines=2

"EFF DATE:"/column=1
agqpersonal:EFF_DATE
"EXP DATE:"/column=25
agqpersonal:EXP_DATE
"TRANS DATE:"/column=48
agqname:TRANS_DATE/NEWLiNE=2

"LOB:         "/column=1           
alt_sfsline:description/column=19

"BILL PLAN:"/COLUMN=47
switch(agqname:bill_plan)
  CASE "AC" : "ACCOUNT CURRENT"
  CASE "DB" : "DIRECT BILL"
  DEFAULT   : "UNKNOWN"/NEWLINE

"PAYMENT PLAN:"/COLUMN=1
--arspayplan:description/column=19

"PREVIOUS POLICY:"/COLUMN=47
agqname:PREVIOUS_POLICY_NO/newline/mask="ZZZZZZZZZ"
           
"FORM OF BUSINESS:"/column=1
switch(agqmaster:form_of_business)
  case "C" : "Corporation"/column=19/newline
  case "I" : "Individual"
  case "P" : "Partnership"
  case "L" : "LLC"
  case "J" : "Joint Venture"
  case "L" : "LLC"
  case "O" : "Organization"
  case "T" : "Other"

if alt_agqmaster:irpm <> 0 then
    {
    "IRPM %:"/COLUMN=1
    alt_agqmaster:irpm/newline/mask="ZZ.ZZ-"
    }

box/noblanklines/noheading             
if agqname:spec_comm_rate <> 0 then
    {
    "SPECIAL COMM:"/COLUMN=1
    agqname:SPEC_COMM_rate/mask="ZZ.ZZ"/duplicates/column=19
    SWITCH(alt_agqmaster:SPLIT_COMM)
      CASE "A" : " - AGCY ONLY"
      CASE "B" : " - AGCY/CO  "
      DEFAULT  : ""
    }
end box/newlines=2

box/noblanklines/noheading
--if alt_agqmaster:terrorism_premium <> 0 or
 --  alt_agqmaster:total[2] <> 0 then
    {
    "TOTAL:"/column=25
    alt_agqmaster:total[18] - alt_agqmaster:total[2]/column=40/mask="$$,$$$,$$$.99"/newline
    }
if alt_agqmaster:total[19] <> 0 then 
    {
    "IRPM:"/column=25
    alt_agqmaster:total[10]/column=40/mask="$$,$$$,$$$.99"/newline
    }
if alt_agqmaster:total[2] <> 0 then
    {
    "EQUIPMENT BREAKDOWN:"/column=25
    alt_agqmaster:total[2]/column=40/mask="$$,$$$,$$$.99"/newline
    }
if alt_agqmaster:terrorism_premium <> 0 then
    {
    "TERRORISM:"/column=25
    alt_agqmaster:terrorism_premium/column=40/mask="$$,$$$,$$$.99"/newline
    }
if alt_scipscontrol:total_premium_wording[1] <> "" then
    {
     uppercase(alt_scipscontrol:total_premium_wording[1])/column=25
    }
else
    {
    "FINAL TOTAL:"/column=25
    }
if alt_agqmaster:total[19] = 0 then
    {
    alt_agqmaster:total[18] + alt_agqmaster:terrorism_premium/column=40/mask="$$,$$$,$$$.99"
    }
else
    {
    alt_agqmaster:total[19] + alt_agqmaster:terrorism_premium/column=40/mask="$$,$$$,$$$.99"
    }
IF alt_agqmaster:minimum_prem_applies = "Y" then
    "M.P."/newline
else
    ""                 
uppercase(alt_scipscontrol:surcharge_wording)/column=25
alt_agqmaster:surcharge/column=40/mask="$$,$$$,$$$.99"/newline
if alt_scipscontrol:total_amount_due_wording[1] <> "" then
    {
    uppercase(alt_scipscontrol:total_amount_due_wording[1])/column=25
    if alt_agqmaster:total[19] = 0 then
        {
        alt_agqmaster:surcharge + 
        alt_agqmaster:total[18] + 
        alt_agqmaster:terrorism_premium/column=40/mask="$$,$$$,$$$.99"/newline
        }
    else
        {
        alt_agqmaster:surcharge + 
        alt_agqmaster:total[19] + 
        alt_agqmaster:terrorism_premium/column=40/mask="$$,$$$,$$$.99"/newline
        }
    }
end box/newline=2
 
box/noblanklines/noheadings/column=1
alt_sfsAGENT:NAME[1]/COLUMN=1/newline
alt_sfsagent:name[2]/COLUMN=1/NEWLINE
alt_sfsagent:name[3]/column=1/newline
alt_sfsagent:address[1]/COLUMN=1/NEWLINE
alt_sfsagent:address[2]/column=1/newline
alt_sfsagent:address[3]/column=1/newline          
box/noblanklines/noheadings/squeeze/column=1
alt_sfsagent:CITY + ","/COLUMN=1
alt_sfsagent:str_state
if alt_sfsagent:zipcode[1,4] = 0 then
    {
     alt_sfsagent:ZIPCODE/mask="99999"
     }

else  
    {
    alt_sfsagent:zipcode/mask="99999-9999"/newline
    }
alt_sfsagent:TELEPHONE[1]/COLUMN=1/mask="(999) 999-9999"
end box                   
end box
