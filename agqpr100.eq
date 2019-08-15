/* agqpr100.eq

   November 20, 2000 

   SCIPS.com, Inc.

   quote worksheet for MSO BOP
*/ 

DEFINE STRING I_NAME[30] = agqgeneral:business_name[1]

include "renaeq1.inc"

DEFINE NUMBER L_ZIP_CODE[9] = agqgeneral:zipcode

DEFINE STRING L_ZIP = STR(L_ZIP_CODE,"999999999")
              l_policy_string[9] = str(agqname:previous_policy_no)

define signed ascii number l_amount = 0 ;

define string l_money_limits = "$" + str(agqgeneral:money_limit_on) + "/" +
                               "$" + str(agqgeneral:money_limit_off)
define string l_burglary_limits = "$" + str(agqgeneral:burglary_limit_on) + "/" +
                                  "$" + str(agqgeneral:burglary_limit_off)
 
define file alt_agqmaster = access agqmaster, set
agqmaster:app_no = agqgeneral:app_no, generic 

define file alt_agqtotals = access agqtotals, set
agqtotals:app_no = agqgeneral:app_no, generic 

define file alt_agqmastsupp = access agqmastsupp, set
agqmastsupp:app_no = agqgeneral:app_no, 
agqmastsupp:line_of_business = agqgeneral:line_of_business, exact 

define file alt_bpscredits = access bpscredits, set
bpscredits:company_id       = agqgeneral:company_id,
bpscredits:state            = agqgeneral:state,
bpscredits:line_of_business = agqgeneral:line_of_business, generic

define file alt_agqlocation = access agqlocation, set
agqlocation:app_no = agqgeneral:app_no,
agqlocation:prem_no = agqgeneral:prem_no,
agqlocation:build_no = agqgeneral:build_no, generic

define file alt_agqgeneral2 = access agqgeneral2, set
agqgeneral2:app_no = agqgeneral:app_no,
agqgeneral2:prem_no = agqgeneral:prem_no,
agqgeneral2:build_no = agqgeneral:build_no, generic

define file alt_agqend = access agqend, set
agqend:app_no = agqgeneral:app_no, 
agqend:prem_no = agqgeneral:prem_no,
agqend:build_no = agqgeneral:build_no, generic

define file alt_agqend1 = access agqend, set
agqend:app_no = agqgeneral:app_no, 
agqend:prem_no  = 0,
agqend:build_no = 0, generic

define file alt_agqsupp = access agqsupp, set
agqsupp:app_no = agqgeneral:app_no, 
agqsupp:prem_no = agqgeneral:prem_no,
agqsupp:build_no = agqgeneral:build_no, generic

define file alt_sfsagent = access sfsagent, set
sfsagent:company_id = agqgeneral:company_id,
sfsagent:agent_no = agqgeneral:agent_no, generic
                   
define file alt_sfscomun = access sfscomun, set
sfscomun:company_id= agqgeneral:company_id,
sfscomun:commercial_underwriter= alt_sfsagent:commercial_underwriter, generic  

define file alt_sfspayortype = access sfspayortype, set
sfspayortype:company_id = agqgeneral:company_id,
sfspayortype:payor_code = alt_agqsupp:mortgage_type_1, generic

define file alt_sfsmorttype = access sfsmorttype, set
sfsmorttype:company_id = agqgeneral:company_id,
sfsmorttype:mortgage_code = alt_agqsupp:mortgage_type_2, generic
     
define file alt_sfsmort = access sfsmort, set
sfsmort:company_id = agqgeneral:company_id,
sfsmort:mortgage_id = alt_agqsupp:mortgage_id, generic

define file bpsdefault_alt = access bpsdefault,
                                set bpsdefault:company_id       = agqgeneral:company_id,
                                    bpsdefault:line_of_business = agqgeneral:line_of_business,
                                    bpsdefault:form             = agqgeneral:form, exact  

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
                   sfsstate:company_id = agqgeneral:company_id ,
                   sfsstate:state = agqgeneral:state,
                   sfsstate:county= 000, generic

define file alt1_sfsstate = access sfsstate, set
                   sfsstate:company_id = agqgeneral:company_id,
                   sfsstate:state = agqgeneral:state,
                   sfsstate:county = agqgeneral:county, generic

define file alt_sfsline = access sfsline, set    
sfsline:company_id = agqgeneral:company_id,
sfsline:line_of_business = agqname:line_of_business,
sfsline:lob_subline = "00", generic

define unsigned ascii number l_liability[8] = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                                  alt_agqmastsupp:liability_code
                                              else
                                                  alt_agqmaster:liability_code

define file alt_sfsliability = access sfsliability, set
                               sfsliability:company_id = agqgeneral:company_id,

                               sfsliability:state = agqgeneral:state,
                               sfsliability:line_of_business = agqgeneral:line_of_business,
                               sfsliability:liability_code = l_liability, generic



define file alt1_sfsline = access sfsline, 
                             set sfsline:company_id = agqgeneral:company_id ,
                             sfsline:line_of_business = agqgeneral:line_of_business,
                             sfsline:lob_subline = "00", generic
    
define file alt_sfsfob = access sfsfob, 
              set sfsfob:company_id = agqgeneral:company_id,
                  sfsfob:form_of_business = alt_agqmaster:form_of_business,
                  generic

define file scipscontrol_alias = access scipscontrol,
            set scipscontrol:company_id = agqgeneral:company_id,
                scipscontrol:state      = agqgeneral:state, 
                scipscontrol:lob_code   = alt1_sfsline:lob_code, exact
    
define unsigned ascii number l_form[2] = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:form
                                         else
                                             alt_agqmaster:form

define file alt_sfsform = access sfsform, set
sfsform:company_id = agqgeneral:company_id,
sfsform:state = agqgeneral:state,
sfsform:line_of_business = agqgeneral:line_of_business,
sfsform:policy_form = l_form, generic
                 

define file alt_scipscontrol = access scipscontrol, 
                                  set scipscontrol:company_id = agqgeneral:COMPANY_ID,
                                      scipscontrol:state      = agqgeneral:state,
                                      scipscontrol:lob_code   = alt_SFSLINE:LOB_CODE, exact

define string l_extend_hired_nonowned = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                            agqmastsupp:extend_hired_nonowned
                                        else
                                            agqmaster:extend_hired_nonowned
 
define string l_delete_hired_nonowned = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                            agqmastsupp:delete_hired_nonowned
                                        else
                                            agqmaster:delete_hired_nonowned
 
define signed ascii number l_delete_hired_nonowned_premium = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                                     alt_agqmastsupp:hired_nonowned_premium
                                                 else
                                                     alt_agqmaster:hired_nonowned_premium
 
define signed ascii number l_extend_hired_nonowned_premium = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                                     alt_agqmastsupp:hired_nonowned_premium
                                                 else
                                                     alt_agqmaster:hired_nonowned_premium
 
define file alt_bpsdefault = access bpsdefault, set
bpsdefault:company_id = agqgeneral:company_id,
bpsdefault:line_of_business = agqgeneral:line_of_business, generic

where agqgeneral:app_no = agqprint1:app_no

LIST
/NOPAGEHEADINGS
/NOBANNER
/NOTOTALS
/DOMAIN="agqgeneral"
/INLINE
/NOHEADIngs
/noduplicates


if ((agqmastsupp:line_of_business one of 5, 50 and
   agqname:line_of_business = 99 and
   agqgeneral:company_id = "LEBINS") or
   agqgeneral:line_of_business <> 99) then
box/noblanklines/noheadings/duplicates/column=1
"LOCATION:"/COLUMN=30
agqgeneral:PREM_NO/MASK="ZZZ9"/NEWLINE/column=42
"BUILDING:"/COLUMN=30 
agqgeneral:BUILD_NO/MASK="ZZZ9"/NEWLINE=2/column=42

/*
"LOCATION:"/column=1
if alt_agqlocation:app_no = agqgeneral:app_no and
   alt_agqlocation:prem_no  = agqgeneral:prem_no and
   alt_agqlocation:build_no = agqgeneral:build_no then
    {
    trun(alt_agqlocation:address) + " " + trun(alt_agqlocation:CITY) + ", " +
    trun(alt_agqlocation:str_state) + " " + trun(alt_agqlocation:str_zipcode)/column=20/newline
    }
else
    "No location has been entered"/column=20/newline/noduplicates
    }
       
"BUSINESS DESCRIPTION:"/column=1
trun(agqgeneral:BUSINESS_DESC[1]) + " " + trun(agqgeneral:business_desc[2])/COLUMN=30/newline=2
*/

"ZIP CODE:"/column=1
agqgeneral:str_zipcode/mask="99999-9999"/newline/column=15

"STATE:"/COLUMN=1
alt_sfsstate:description/column=15

"COUNTY:"/COlumn=30
ALT1_sfsstate:DESCRIPTION/newline

"CONSTRUCTION: "/column=1
agqgeneral:CONSTRUCTION/MASK="ZZZ"/COLUMN=20

"SPRINKLERS:"/COLUMN=30
agqgeneral:SPRINKLERS/COLUMN=52

"PROTECTION:"/COLUMN=65
agqgeneral:PROTECTION/NEWLINE/COLUMN=83

"TERRITORY: "/column=1
agqgeneral:TERRITORY/MASK="ZZZ"/COLUMN=20

"TYPE:"/COLUMN=30
agqgeneral:BOP_TYPE/COLUMN=52
BPSTYPE:DESCRIPTION

"TENANT:"/COLUMN=65
agqgeneral:TENANT/newline/COLUMN=84
                   
"YR CONSTRUCTION:"/COLUMN=1
agqgeneral:CONSTRUCTION_YEAR/COLUMN=19/MASK="ZZZZ"      
                             
"% OCCUPIED:"/column=30
agqgeneral:percent_occupied/column=50

"SINGLE OCCUPANCY:"/COLUMN=65
agqgeneral:SINGLE_OCCUPANCY/COLUmn=84/newline 
 
"FIRE ALARM:"/column=1
if agqgeneral:alarm_factor <> 0 and
   agqgeneral:alarm_option[1] = "Y" then
    agqgeneral:alarm_factor
else
    agqgeneral:ALARM_CREDIT[1]/COLUMN=21

"BURGLAR ALARM:"/column=30
if agqgeneral:alarm_factor <> 0 and
   agqgeneral:alarm_option[2] = "Y" then
    agqgeneral:alarm_factor
else
    agqgeneral:ALARM_CREDIT[2]/COLUMN=50

"SUPERIOR CONDITIONS:"/column=65
if agqgeneral:alarm_factor <> 0 and
   agqgeneral:alarm_option[3] = "Y" then
    agqgeneral:alarm_factor
else
    agqgeneral:ALARM_CREDIT[3]/COLUMN=84/newline

if alt_sfsline:lob_code one of "CPORTFOLIO" then
  {
    "MULTIPLE LOCATION %:"/COLUMN=1
    alt_agqmastsupp:LOCATION_CREDIT/COLUMN=21
  }
else
    {
    "MULTIPLE LOCATION %:"/COLUMN=1
    alt_agqmaster:LOCATION_CREDIT/COLUMN=21
    }

"LOSS FREE CREDITS:"/column=30
agqgeneral:loss_years/column=50/newline

if agqgeneral:company_id one of "DELOS", "GGUND" then
    {
    "TERRITORY FACTOR:"/column=30
    agqgeneral:rating_territory_factor/column=50
    "SPECIAL EXPOSURE:"/column=65
    agqgeneral:special_exposure_factor/column=84/newline
    }
else
if agqgeneral:company_id <> "FARMERS" then
    {
    "TERRITORY FACTOR:"/column=30
    agqgeneral:rating_territory_factor/column=50/newline
    }
 
if agqgeneral:company_id not one of "DELOS", "GGUND" then
    {
    "TERRITORY BUILDING:"/column=1
    agqgeneral:territory_factors[1]/column=21

    "TERRITORY PROPERTY:"/column=30
    agqgeneral:territory_factors[2]/column=50

    "TERRITORY EXPANDED:"/column=65
    agqgeneral:territory_factors[3]/column=84/newline
    }

"COASTAL TIER:"/column=1
agqgeneral:tier/column=21

"SPECIAL ENHANCEMENT:"/column=30
switch(agqgeneral:special_enhancement)
  case 0  : "N"
  default : "Y"/column=52/newline

if agqgeneral:class_code > 0 then
    {
    "CLASS CODE:"/column=1
    agqgeneral:CLASS_CODE/MASK="ZZZZZ"/COLUMN=18
    bpsclass_type:alpha_look/newline/column=25
    }

"RATE NO:"/column=1
agqgeneral:RATE_NO/COLUMN=21/mask="ZZ"
"RATE GROUP:"/COLUMN=30
agqgeneral:RATE_GROUP/newline=2/mask="ZZ"/column=51

"1-4 Garden Apt Type Unit:"/column=1
switch(agqgeneral:garden_type)
  case 1  : "Y"
  default : "N"
if agqgeneral:garden_type = 1 then
    (100 - (alt_bpscredits:apt_condo_factor[2] * 100))/mask="ZZ%"
"2-4 Family Garden Apt:"/column=65
switch(agqgeneral:family_apt)
  case 1  : "Y"
  default : "N"
if agqgeneral:family_apt = 1 then
    (100 - (alt_bpscredits:apt_condo_factor[1] * 100))/mask="ZZ%"
""/newline=2

"DELETE LOSS OF INCOME:"/column=1
agqgeneral:delete_loss_income/newline/column=30
 
"LOSS OF INCOME TO EXTRA EXPENSE & RENTAL INCOME ONLY: "/column=1
agqgeneral:LIMIT_LOSS_INCOME/NEWLINE

"LOSS OF BUSINESS INCOME LIMIT: "/column=1
if agqgeneral:loss_income_limit = 0 and
   agqgeneral:delete_loss_income = "N" then  
    {
    "Included"/newline
    }
else  
    {
    agqgeneral:LOSS_INCOME_LIMIT/NEWLINE/mask="$$,$$$,$$$"
    }

if agqgeneral:wholesaler = "Y" then
    box/noblanklines/noheadings/duplicates 
    "WHOLESALER:"/column=1
    agqgeneral:wholesaler/column=24
    "% OF COVERAGE B LIMIT:"/column=37
    agqgeneral:wholesaler_percent/newline/column=57
    end box/newline

/*"LIMITS"/align=alt_agqmaster:off_premises_limit
"PREMIUM"/align=alt_agqmaster:off_premises_premium
"LIMITS"/align=agqgeneral:mechanical_limit
"PREMIUM"/NEWLINE/align=agqgeneral:mechanical_premium*/
 
"OFF PREMISES:"/column=1          
if agqgeneral:off_premises_limit = alt_agqmaster:off_premises_limit or
   agqgeneral:off_premises_limit = 0 then
    {
    alt_agqmaster:off_premises_limit/mask="$$$,$$$"/column=25
    alt_agqmaster:off_premises_premium/mask="ZZ,ZZZ.99-"/column=32
    }
else 
    {
    agqgeneral:off_premises_limit/mask="$$$,$$$"/column=25
    agqgeneral:off_premises_premium/mask="ZZ,ZZZ.99-"/column=32
    }

"MECHANICAL BREAKDOWN:"/column=46
agqgeneral:MECHANICAL_LIMIT/column=68/mask="$$$,$$$"
agqgeneral:MECHANICAL_PREMIUM/column=75/mask="ZZ,ZZZ.99-"/newline
                                             
"DELETE HIRED/NONOWNED:"/column=1
l_delete_hired_nonowned/align=alt_agqmaster:off_premises_limit
if l_delete_hired_nonowned = "Y" then
  {
    l_delete_hired_nonowned_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
  }
else
  {
    l_amount/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
  }

/*if sfscompany:special_territory_rating = 1 then
    {
    "TERRITORY CHARGE/CREDIT:"/column=46
    agqgeneral:territory_charge_credit/NEWLINE=2/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium                          
    }
*/
if sfscompany:optional_coverage_screen = 1 then
    {
    "FUEL PUMP CHARGE:"/column=46
    agqgeneral:fuel_pump_charge/mask="ZZ,ZZZ.99"/align=agqgeneral:mechanical_premium/newline=2
    }

--if sfscompany:optional_coverage_screen not one of 1 and
--   sfscompany:special_territory_rating not one of 1 then
--    {
--    ""/newline=2
--    }

"CUSTOMERS' PROPERTY:"/column=46
agqgeneral:CUSTOMER_PROP_LIMIT/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
agqgeneral:CUSTOMER_PROP_PREMIUM/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium

"EXTEND HIRED/NONOWNED:"/column=1
if alt_sfsline:lob_code one of "CPORTFOLIO" then
    {
    alt_agqmastsupp:extend_hired_nonowned/duplicates/align=alt_agqmaster:off_premises_limit
    if alt_agqmastsupp:extend_hired_nonowned = "Y" then
        {
        alt_agqmastsupp:Hired_nonowned_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
        }
    else
        {
        l_amount/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
        }
    }
else
    {
    alt_agqmaster:extend_hired_nonowned/duplicates/align=alt_agqmaster:off_premises_limit
    if alt_agqmaster:extend_hired_nonowned = "Y" then
        {
        alt_agqmaster:Hired_nonowned_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
        }
    else
        {
        l_amount/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
        }
    }
 
"SUPPLIES/MATERIALS:   "/column=46
agqgeneral:supplies_LIMIT/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
agqgeneral:supplies_PREMIUM/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium

"OUTDOOR SIGNS:"/column=1
agqgeneral:SIGNS_LIMIT/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
agqgeneral:SIGNS_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
         
if agqgeneral:company_id <> "LEBINS" then
{
"POLLUTION CLEANUP:"/column=46
agqgeneral:POLLUTION_LIMIT/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
agqgeneral:POLLUTION_PREMIUM/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium
}
else
{
"DEBRIS REMOVAL:"/column=46
agqgeneral:DEBRIS_REMOVAL_LIMIT/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
agqgeneral:POLLUTION_PREMIUM/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium
}

"SIGNS DEDUCTIBLE:"/column=1
agqgeneral:SIGNS_DEDUCTIBLE[1]/mask="ZZ,ZZ9"/align=alt_agqmaster:off_premises_limit
                                     
"INFLATION GUARD %:"/column=46
agqgeneral:auto_percent/align=agqgeneral:mechanical_limit
agqgeneral:auto_premium/mask="ZZ,ZZZ.99-"/newline/align=agqgeneral:mechanical_premium

"BUILDING CODE/LAW:"/column=1
agqgeneral:BUILDING_CODE_percent/align=alt_agqmaster:off_premises_limit
agqgeneral:BUILDING_CODE_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium

"LIMIT WATER BACKUP:"/column=46
agqgeneral:water_backup_limited/newline/align=agqgeneral:mechanical_limit

"EXTERIOR GLASS:"/column=1
agqgeneral:GLASS_LIMIT/mask="ZZZ,ZZ9"/align=alt_agqmaster:off_premises_limit 
if scipscontrol_alias:glass_square_feet = 0 then
  {
    "LF"
  }
else
  {
    "SQ FT"
  }
agqgeneral:GLASS_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium

"WATER BACKUP LIMIT:   "/column=46
if agqgeneral:water_backup_premium <> 0 then
    {
    agqgeneral:water_backup_limit/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    }  
else    
    {
    "      0"/align=agqgeneral:mechanical_limit
    }
agqgeneral:water_backup_premium/mask="ZZ,ZZZ.99-"/newline/align=agqgeneral:mechanical_premium  

"INCLUDE GLASS DEDUCTIBLE:"/column=1
agqgeneral:include_glass_deductible/align=alt_agqmaster:off_premises_limit

"DELETE WATER BACKUP EXCL:"/column=46
agqgeneral:water_backup_exclusion/newline/align=agqgeneral:mechanical_limit

"BURGLARY/ROBBERY:"/column=1              
if agqgeneral:burglary_limit_on <> 0 then
    {            
    l_burglary_limits/align=alt_agqmaster:off_premises_limit
    agqgeneral:BURGLARY_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
    }
else
    {
    "0"/align=alt_agqmaster:off_premises_limit
    agqgeneral:burglary_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
    }

"FIRE LEGAL:"/column=46
agqgeneral:FIRE_LIMIT/mask="$$$,$$$,$$$"/align=agqgeneral:mechanical_limit 
agqgeneral:FIRE_PREMIUM/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium

"ATTACH BU5001:"/column=1
agqgeneral:ATTACH_BU5001/align=alt_agqmaster:off_premises_limit

"VALUABLE PAPERS:"/column=46
agqgeneral:VALUABLE_PAPERS_LIMIT/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
agqgeneral:VALUABLE_PAPERS_PREMIUM/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium

"MONEY/SECURITIES:"/column=1 
if l_money_limits <> "" then
    { 
    l_money_limits/align=alt_agqmaster:off_premises_limit
    agqgeneral:MONEY_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
    }
else
    {
    "0"/align=alt_agqmaster:off_premises_limit
    agqgeneral:money_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
    }

"WIND DEDUCTIBLE:"/column=46
agqgeneral:wind_deductible/mask="ZZ,ZZ9"/newline/align=agqgeneral:mechanical_limit

"ACCOUNTS RECEIVABLE:"/column=1
agqgeneral:AR_LIMIT/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
agqgeneral:AR_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium

"BOILERS:"/column=46
agqgeneral:boilers/align=agqgeneral:mechanical_limit
agqgeneral:boilers_premium/newline/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium

if agqgeneral:company_id not one of "FARMERS", "FLEMINGTON" then
    {
    "HURRICANE DEDUCTIBLE:"/column=1
    agqgeneral2:hurricane_deductible/mask="ZZZZZ%"/align=alt_agqmaster:off_premises_limit/newline
    }
else
    {
    "HURRICANE DEDUCTIBLE:"/column=1
    agqgeneral2:hurricane_deductible/mask="ZZZZZ%"/align=alt_agqmaster:off_premises_limit
    }

if agqgeneral:company_id one of "FARMERS", "FLEMINGTON" then
    {
    "DEBRIS REMOVAL:"/column=46
    agqgeneral:debris_removal_limit/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral:debris_removal_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline 
    }

box/noblanklines/noheading/column=1
if agqgeneral:receipts <> 0 and
   agqgeneral:company_id <> "FLEMINGTON" then
    box/noblanklines/noheading/column=1
    "UTILITY SERVICES:"/column=1
     agqgeneral:UTILITY_LIMIT/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
     agqgeneral:UTILITY_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
    "RESTAURANT:"/column=46
    agqgeneral:receipts/align=agqgeneral:mechanical_limit
    agqgeneral:restaurant_enhancement/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium
    end box
else
if agqgeneral:signs_not_attached_limit <> 0 then
    box/noblanklines/noheading/column=1                                   
    "UTILITY SERVICES:"/column=1
     agqgeneral:UTILITY_LIMIT/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
     agqgeneral:UTILITY_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
    "SIGNS NOT ATTACHED:"/column=46
    agqgeneral:signs_not_attached_limit/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral:signs_not_attached_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium 
    end box
else
    box/noblanklines/noheading/column=1
    "UTILITY SERVICES:"/column=1
     agqgeneral:UTILITY_LIMIT/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
     agqgeneral:UTILITY_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
     end box

if agqgeneral:company_id one of "FARMERS", "FLEMINGTON" then
    box/noblanklines/noheading/column=1
    "LOSS INCOME INTERRUPT:"/column=46
    agqgeneral2:interruption/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral2:interruption_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline

    "ELECTRONIC DATA COV:"/column=1
    agqgeneral2:electronic_data/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
    agqgeneral2:electronic_data_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium

    "LOSS INCOME DEPENDENT:"/column=46
    agqgeneral2:dependent_property/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral2:dependent_property_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline 

    "CREDIT CARD/FORGERY:"/column=1
    agqgeneral2:credit_card/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
    agqgeneral2:credit_card_premium/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 

    "EMPLOYEE DISHONESTY:"/column=46
    agqgeneral2:employee_dis_limit/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral2:employee_dis_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline 

    if agqgeneral:receipts <> 0 or
       agqgeneral:class_code one of 81, 82 then
        box/noblanklines/noheading
        "RESTAURANT:"/column=01
        agqgeneral:receipts/align=alt_agqmaster:off_premises_limit
        agqgeneral:restaurant_enhancement/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium
        end box

    "NO EMPLOYEES:"/column=46
    agqgeneral2:employee_dis_no_employees/mask="ZZZZ"/align=agqgeneral:mechanical_limit/newline

    end box
end box/newline

if agqgeneral:company_id = "NWIC" and
   agqgeneral:state = 29 then
    box/noblanklines/noheading
    "CREDIT CARD/FORGERY:"/column=1
    agqgeneral2:credit_card/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
    agqgeneral2:credit_card_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
    "ELECTRONIC DATA:"/column=46
    agqgeneral2:electronic_data/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral2:electronic_data_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline
    "DEPENDENT PROPERTY:"/column=1
    agqgeneral2:dependent_property/mask="$$$,$$$"/align=alt_agqmaster:off_premises_limit
    agqgeneral2:dependent_property_PREMIUM/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium 
    "INTERRUPTION:"/column=46
    agqgeneral2:interruption/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral2:interruption_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium 
    end box/newline=2

if sfscompany:special_territory_rating = 1 and
   agqgeneral:no_pools = 0 then
    {
    "TERRITORY CHARGE/CREDIT:"/column=46
    agqgeneral:territory_charge_credit/NEWLINE=2/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium                          
    }
else
if agqgeneral:company_id <> "FARMERS" then
    {
    "TERRITORY CHARGE/CREDIT:"/column=46
    agqgeneral:territory_charge_credit/NEWLINE/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium                          
    }

if agqgeneral:no_pools <> 0 then
    {
    "NO POOLS:"/column=1
    agqgeneral:no_pools/mask="ZZZZ"/align=alt_agqmaster:off_premises_limit
    agqgeneral:pool_premium/mask="ZZ,ZZZ.99"/align=alt_agqmaster:off_premises_premium/newline
    }

if agqgeneral:company_id not one of "FARMERS", "FLEMINGTON" then
    {
    "DEBRIS REMOVAL:"/column=46
    agqgeneral:debris_removal_limit/mask="$$$,$$$"/align=agqgeneral:mechanical_limit
    agqgeneral:debris_removal_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline 
    }

--if sfscompany:optional_coverage_screen = 1 then
--    {
--    "FUEL PUMP CHARGE:"/column=46
--    agqgeneral:fuel_pump_charge/mask="ZZ,ZZZ.99"/align=agqgeneral:mechanical_premium/newline=2
--    }

"LIABILITY FLAT CHARGE:"/column=1
agqgeneral:liability_charge/mask="ZZ,ZZZ.99-"/align=alt_agqmaster:off_premises_premium /newline

if sfscompany:boiler_rating = 1 then
box/noblanklines/noheading

"EPL LIMIT/DEDUCT:"/column=1
str(agqepl:epl_limit,"Z,ZZZ,ZZZ") + "/" + str(agqepl:epl_deductible,"ZZZZZ")/align=agqgeneral:off_premises_limit
agqepl:epl_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:off_premises_premium

if agqepl:third_party = 1 then
    box/noblanklines/noheading/column=1
    "Third Party Option:"/column=46
    agqepl:third_party_premium/mask="ZZ,ZZZ.99-"/align=agqgeneral:mechanical_premium/newline
    if agqepl:epl_limit < 500000 then
        box/noblanklines/noheading/column=1
        "EPL Percent:"/column=1
        agqepl:epl_percent/mask="ZZ.ZZ%"/align=alt_agqmaster:off_premises_premium
        end box
    end box/newline
else
if agqepl:epl_limit < 500000 then
    box/noblanklines/noheading
    "EPL Percent:"/column=1
    agqepl:epl_percent/mask="ZZ.ZZ%"/align=agqgeneral:off_premises_limit
    end box/newline
end box/newline=2

if sfscompany:optional_coverage_screen not one of 1 and
   sfscompany:special_territory_rating not one of 1 then
    {
    ""/newline=2
    }
--end box

--followed by

--box/noblanklines/noheading
""/newline
"LIMITS"/align=alt_agqmaster:off_premises_limit
"PREMIUM"/align=alt_agqmaster:off_premises_premium
"LIMITS"/align=agqgeneral:mechanical_limit
"PREMIUM"/NEWLINE/align=agqgeneral:mechanical_premium
if agqgeneral:liability_only = 0 then
{
"BUILDING LIMIT:"/column=1
agqgeneral:BUILDING_LIMIT/MASK="$$,$$$,$$$"/align=alt_agqmaster:off_premises_limit
agqgeneral:BUILDING_PREMIUM/MASK="$$$,$$$.99"/align=alt_agqmaster:off_premises_premium
}
else
{
"LIABILITY ONLY:"/column=1
agqgeneral:BUILDING_LIMIT/MASK="$$,$$$,$$$"/align=alt_agqmaster:off_premises_limit
agqgeneral:BUILDING_PREMIUM/MASK="$$$,$$$.99"/align=alt_agqmaster:off_premises_premium
}

"PERSONAL PROPERTY:"/column=46
agqgeneral:PROPerty_LIMIT/MASK="$$,$$$,$$$"/align=agqgeneral:mechanical_limit
agqgeneral:PROPERTY_PREMIUM/MASK="$$$,$$$.99"/newline/align=agqgeneral:mechanical_premium

"OTHER STRUCTURES"/column=1
agqgeneral:other_structures/mask="$$,$$$,$$$"/align=alt_agqmaster:off_premises_limit
 
"EXPANDED PREMIUM:"/column=46
agqgeneral:property_special/mask="$$$,$$$.99"/newline/align=agqgeneral:mechanical_premium/duplicates

"ACV BUILDING:"/column=1
agqgeneral:ACV_building/align=alt_agqmaster:off_premises_limit
agqgeneral:ACV_building_PREMIUM/mask="$$$,$$$.99"/align=alt_agqmaster:off_premises_premium

"ACV CONTENTS:"/column=46
agqgeneral:ACV_CONTENTS/align=agqgeneral:mechanical_limit
agqgeneral:ACV_CONTENTS_PREMIUM/NEWLINE=4/mask="$$$,$$$.99"/align=agqgeneral:mechanical_premium
end box/newline=2
                                       
followed by
 
""/newline=2
if alt_agqend1:prem_no <> 0 or
   alt_agqend:prem_no <> 0 then
    { 
    if alt_agqend1:lob_end_code one of "X" or
       alt_agqend:lob_end_code one of "X" then
        {
        box/noheadings/noblanklines/column=1 
        "LOC"/column=1
        "BUILD"/COLUMN=9
        "FORM/EDITION"/column=25
        "PREMIUM"/newline/column=75
        end box                     
        }
    }

followed by

if alt_agqend1:lob_end_code = "X" then
box/noheadings/noblanklines /column=1
alt_agqend1:prem_no/duplicates/column=1/mask="ZZZ9"
alt_agqend1:build_no/duplicates/column=9/mask="ZZZ9" 
trun(alt_agqend1:form_edition[1,7]) + " " + alt_agqend1:description[1,50]/column=20/duplicates
alt_agqend1:premium/mask="ZZ,ZZZ.99-"/duplicates/align=agqgeneral:mechanical_premium
end box

followed by 

if alt_agqend:lob_end_code = "X" then
box/noheadings/noblanklines /column=1
alt_agqend:prem_no/duplicates/column=1/mask="ZZZ9"
alt_agqend:build_no/duplicates/column=9/mask="ZZZ9" 
alt_agqend:code + " " + alt_agqend:description[1,50]/column=20/duplicates
alt_agqend:premium/mask="ZZ,ZZZ.99-"/duplicates/align=agqgeneral:mechanical_premium
end box/newlines=2

followed by 
                    
if alt_agqsupp:prem_no <> 0 then
    box/noblanklines/noheadings/column=1
    "LOC"/column=1/duplicates
    "BUILD"/COLUMN=9
    "ADDITIONAL INTEREST"/newline/column=25
    end box

followed by
    
if alt_agqsupp:prem_no <> 0 and
   alt_agqsupp:agent_payor = 0 then
box/noblanklines/noheadings
alt_agqsupp:prem_no/duplicates/column= 1
alt_agqsupp:build_no/duplicates/column=9
if alt_agqsupp:mortgage_id <> "" then
    {
    trun(alt_sfsmort:name[1]) + " " +
    trun(alt_sfsmort:address[1]) + " " +
    trun(alt_sfsmort:CITY) + ", " +
    trun(alt_sfsmort:str_state) + " " +
    trun(alt_sfsmort:str_ZIPCODE)/column=20
    }
else
    {  
    trun(alt_agqsupp:NAME[1]) + " " +
    trun(alt_agqsupp:address[1]) + " " +
    trun(alt_agqsupp:CITY) + ", " +
    trun(alt_agqsupp:str_state) + " " +
    trun(alt_agqsupp:str_ZIPCODE)/column=20
    }    
end box/newlines
                     
followed by  
           
if agqmisc:app_no = agqgeneral:app_no then
{        
"MISCELLANEOUS"/newline=2
"DESCRIPTION"/column=18
"PREMIUM"/column=50/newline=2
agqmisc:description/column=11
agqmisc:premium/column=52/mask="ZZZZZ-"
}
""/newline=2

sorted by agqgeneral:app_no/newpage 
          agqgeneral:prem_no
          agqgeneral:build_no

end of report                             
""/newline=2
"DATE PRINTED:"/column=1
todaysdate/mask="MM/DD/YYYY"
"PRINTED BY:"/column=40
username/newline
if agqgeneral:company_id not one of "FLEMINGTON" then
    box/noblanklines/noheading
    "UNDERWRITER:"/column=1
    alt_sfscomun:name
    end box

top of report
sfscompany:name[1]/column=30/newline=2
"APP NO:"/column=1
agqgeneral:app_no/column=12

include "renaeq2.inc"/newline=2/column=36

"EFF DATE:"/column=1
agqgeneral:EFF_DATE/column=12
"EXP DATE:"/column=25
dateadd(agqgeneral:EFF_DATE,0,1)/column=35/newline/mask="MM/DD/YYYY"

"LOB:         "/column=1           
trun(alt1_sfsline:description)/column=25/newline
if agqgeneral:special_enhancement = 1 then
    "Enhancement Endorsement"/column=25/newline

"FORM:        "/COLUMN=1
alt_sfsform:description/column=25/newline

if alt_agqmastsupp:app_no = agqgeneral:app_no then
    { 
    "IRPM %:"/COLUMN=1
    alt_agqmastsupp:irpm/newline/mask="Z9.99-"/column=25
    } 
else
    { 
    "IRPM %:"/COLUMN=1
    alt_agqmaster:irpm/newline/mask="Z9.99-"/column=25
    } 

"LIABILITY:"/COLUMN=1
alt_sfsliability:limit/newline/mask="$$,$$$,$$$"/column=25

if alt_sfsline:lob_code = "CPORTFOLIO" then
  {
    "GENERAL AGGREGATE:"/column=1
    alt_agqmastsupp:GENERAL_AGGREGATE/column=25/mask="$$,$$$,$$$"/newline

    "MEDICAL PAYMENTS:"/column=1
    alt_agqmastsupp:MEDical_LIMIT/column=25/mask="$$,$$$,$$$"/newline

    "PERSONAL ADD INJURY:"/column=1
    alt_agqmastsupp:PERSonal_ADD_INJURY/column=25/mask="$$,$$$,$$$"/newline

    "DEDUCTIBLE:  "/COLUMN=1
    alt_agqmastsupp:DEDUCTIBLE/mask="$$,$$$,$$$"/column=25/newline=1
    if agqgeneral:company_id one of "FLEMINGTON" then                                                                                  
      {                                                                                                                                    
        "ENHANCEMENT PREMIUM:"/column=1                                                                                                   
        alt_agqmaster:total[8]/column=25/mask="$$,$$$,$$$"/newline=2                                                                      
      }
  }
else
  {
    "GENERAL AGGREGATE:"/column=1
    alt_agqmaster:GENERAL_AGGREGATE/column=25/mask="$$,$$$,$$$"/newline

    "MEDICAL PAYMENTS:"/column=1
    alt_agqmaster:MEDical_LIMIT/column=25/mask="$$,$$$,$$$"/newline

    "PERSONAL ADD INJURY:"/column=1
    alt_agqmaster:PERSonal_ADD_INJURY/column=25/mask="$$,$$$,$$$"/newline

    "DEDUCTIBLE:  "/COLUMN=1
    alt_agqmaster:DEDUCTIBLE/mask="$$,$$$,$$$"/column=25/newline=2
    if agqgeneral:company_id one of "FLEMINGTON" then                                                                                  
      {                                                                                                                                    
        "ENHANCEMENT PREMIUM:"/column=1                                                                                                   
        alt_agqmaster:total[8]/column=25/mask="$$,$$$,$$$"/newline=2                                                                      
      }
  }

if alt_sfsline:lob_code = "CPORTFOLIO" then
    {
    box/noblanklines/noheading
    "              Total:"/column=10
        alt_agqmastsupp:total[1] +
        alt_agqmastsupp:total[2] +
        alt_agqmastsupp:total[6] +
        --alt_agqmastsupp:total[5] +
        alt_agqmastsupp:total[8]/column=30/mask="$$,$$$,$$$.99"/newline
    if agqgeneral:company_id = "FARMERS" then
         {
         "        EPL Premium:"/column=10
         alt_agqmastsupp:total[9]/column=30/mask="$$,$$$,$$$.99"/newline
         }
    "          Terrorism:"/column=10
    alt_agqmastsupp:terrorism_premium/column=30/mask="$$,$$$,$$$.99"/newline
    if agqgeneral:company_id <> "LEBINS" then
        {
        " Surcharge NJ-PLIGA:"/column=10
        alt_agqmastsupp:surcharge/column=30/mask="$$,$$$,$$$.99"/newline
        }
    "   Total Amount Due:"/column=10
    alt_agqmastsupp:total[20]/column=30/mask="$$,$$$,$$$.99"/newline
    end box/newline
    }
else
if agqgeneral:company_id <> "FARMERS" then
    {
    box/noblanklines/noheading
    "              Total:"/column=10
     If agqgeneral:company_id = "FLEMINGTON" then
       {
         alt_agqmaster:total[1]/column=30/mask="$$,$$$,$$$.99"/newline

       }
     else
       {
        alt_agqmaster:total[1] +
        alt_agqmaster:total[2] +
        alt_agqmaster:total[5] +
        alt_agqmaster:total[6] +
        --alt_agqmaster:total[5] +
        alt_agqmaster:total[8]/column=30/mask="$$,$$$,$$$.99"/newline
       } 
     "          Terrorism:"/column=10
    alt_agqmaster:terrorism_premium/column=30/mask="$$,$$$,$$$.99"/newline
    if agqgeneral:company_id <> "LEBINS" then
        {
        " Surcharge NJ-PLIGA:"/column=10
        alt_agqmaster:surcharge/column=30/mask="$$,$$$,$$$.99"/newline
        }
    "   Total Amount Due:"/column=10
    alt_agqmaster:total[20]/column=30/mask="$$,$$$,$$$.99"/newline
    end box/newline
    }
else
if agqgeneral:company_id = "FARMERS" then
    {
    box/noblanklines/noheading
    "TOTAL:"/column=10
    alt_agqmaster:total[17]/column=30/mask="$$,$$$,$$$.99"/newline
    if alt_agqmaster:total[19] <> 0 then                              
        {
        "IRPM TOTAL:"/column=10
        box/noblanklines/noheading 
        alt_agqmaster:total[1] - alt_agqmaster:total[9]/column=9/mask="$$,$$$,$$$.99-"
        end box/newline
        }                             
    "BOILER & MACHINERY:"/column=10
    alt_agqmaster:total[2]/column=30/mask="$$,$$$,$$$.99"/newline
    "EPL:"/column=10
    alt_agqmaster:total[9]/column=30/mask="$$,$$$,$$$.99"/newline
    "TERRORISM:"/column=10
    alt_agqmaster:terrorism_premium/column=30/mask="$$,$$$,$$$.99"/newline
    if alt_agqmaster:total[7] <> 0 then
        {
        "IDENTITY THEFT:"/column=10
        alt_agqmaster:total[7]/column=30/mask="$$,$$$,$$$.99"/newline
        }
    if alt_scipscontrol:total_premium_wording[1] <> "" then
        {
        uppercase(alt_scipscontrol:total_premium_wording)/column=10
        }
    else
        {
        "FINAL TOTAL:"/column=10
        }
    if alt_agqmaster:total[19] <> 0 then
        {
        alt_agqmaster:total[1] + alt_agqmaster:total[2] + alt_agqmaster:terrorism_premium + alt_agqmaster:total[7]/column=30/mask="$$,$$$,$$$.99"
        }
    else
        {
        alt_agqmaster:total[1] + alt_agqmaster:total[2] + alt_agqmaster:total[9] + alt_agqmaster:terrorism_premium + alt_agqmaster:total[7]/column=30/mask="$$,$$$,$$$.99"
        }
    IF alt_agqmaster:minimum_prem_applies = "Y" then
        "M.P."/newline
    else
        ""                 
    if alt_scipscontrol:total_amount_due_wording[1] <> "" then
        {
        uppercase(alt_scipscontrol:surcharge_wording)/column=10
        alt_agqmaster:surcharge/column=30/mask="$$,$$$,$$$.99"/newline
        uppercase(alt_scipscontrol:total_amount_due_wording[1])/column=10
        if alt_agqmaster:total[19] <> 0 then
            {
            alt_agqmaster:total[19] +
            alt_agqmaster:surcharge/column=30/mask="$$,$$$,$$$.99"/newline
            }
        else
            {
            alt_agqmaster:total[18] +
            alt_agqmaster:surcharge/column=30/mask="$$,$$$,$$$.99"/newline
            }
        }
    else
        {
        uppercase(alt_scipscontrol:surcharge_wording)/column=10
        alt_agqmaster:surcharge/column=30/mask="$$,$$$,$$$.99"/newline
        }  
    end box/newline=2
    }

box/noblanklines/noheadings/column=1

""/newline
alt_sfsAGENT:NAME[1] + " - " + str(alt_sfsagent:agent_no)/COLUMN=1/newline
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
alt_sfsagent:TELEPHONE[1]/mask="(999) 999-9999"/COLUMN=1/newline
end box                   
end box/newline
