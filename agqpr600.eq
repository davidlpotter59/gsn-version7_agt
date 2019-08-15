/* agqpr600.eq

   white hall mutual ins co

   june 4, 1999

   quote worksheet
*/
                                      
define string l_subline = "00"

define file alt_agqmastsupp = access agqmastsupp, set
agqmastsupp:app_no = agqvehicle:app_no,
agqmastsupp:line_of_business = agqvehicle:line_of_business, generic

define file alt_sfsline  = access sfsline, set
sfsline:company_id       = agqvehicle:company_id,
sfsline:line_of_business = agqvehicle:line_of_business,
sfsline:lob_subline      = l_subline, generic

define string i_name   = agqvehicle:business_name[1] 
              i_name_1 = agqvehicle:business_name[2]
              i_name_2 = agqvehicle:business_name[3]

include "renaeq5.inc"

define string l_class_code[5] = if agqvehicle:secondary_class_iso <> 0 then
                                  trun(str(agqvehicle:class_code)) + 
                                  str(agqvehicle:secondary_class_iso)
                              else
                              if agqvehicle:secondary_class <> 0 then
                                  trun(str(agqvehicle:class_code)) + 
                                  str(agqvehicle:secondary_class)
                               else   
                                  trun(str(agqvehicle:class_code))

define unsigned ascii number l_class[5] = val(l_class_code) 
						
     
define string l_dumping = if agqvehicle:type = 1 and
                             agqvehicle:dump = "Y" then
                              "Used in Dumping"
                          else
                          if agqvehicle:type = 1 and
                             agqvehicle:dump = "N" then
                              "Not used in Dumping"
                          else
                              ""
                 
define string l_antitheft = if agqvehicle:type = 2 and
                               agqvehicle:antitheft[1] = "Y" then
                                "Category I antitheft devices"
                            else
                            if agqvehicle:type = 2 and
                               agqvehicle:antitheft[2] = "Y" then
                                "Category II antitheft devices"
                            else
                            if agqvehicle:type = 2 and
                               agqvehicle:antitheft[3] = "Y" then
                                "Category III antitheft or vehicle recovery"
                            else
                            if agqvehicle:type = 2 and
                               agqvehicle:antitheft[4] = "Y" then
                                "Category IV antitheft or vehicle recovery"

define string l_safety = if agqvehicle:type = 2 and
                            agqvehicle:safety <> 0 then
                             str(agqvehicle:safety) + " Safety Features"
 

define unsigned ascii number l_pip_total = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                               alt_agqmastsupp:other_totals[8] +
                                               alt_agqmastsupp:other_totals[10] +
                                               alt_agqmastsupp:other_totals[11] +
                                               alt_agqmastsupp:other_totals[12]
                                           else 
                                               agqmaster:other_totals[8] +
                                               agqmaster:other_totals[10] +
                                               agqmaster:other_totals[11] +
                                               agqmaster:other_totals[12]

define unsigned ascii number l_total_1 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[1]
                                         else
                                             agqmaster:total[1]

define unsigned ascii number l_total_2 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[2]
                                         else
                                             agqmaster:total[2]

define unsigned ascii number l_total_3 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[3]
                                         else
                                             agqmaster:total[3]

define unsigned ascii number l_total_4 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[4]
                                         else
                                             agqmaster:total[4]

define unsigned ascii number l_total_5 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[5]
                                         else
                                             agqmaster:total[5]

define unsigned ascii number l_total_6 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[6]
                                         else
                                             agqmaster:total[6]

define unsigned ascii number l_total_7 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[7]
                                         else
                                             agqmaster:total[7]

define unsigned ascii number l_total_8 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[8]
                                         else
                                             agqmaster:total[8]

define unsigned ascii number l_total_9 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[9]
                                         else
                                             agqmaster:total[9]

define unsigned ascii number l_total_10 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[10]
                                         else
                                             agqmaster:total[10]

define unsigned ascii number l_total_11 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[11]
                                         else
                                             agqmaster:total[11]

define unsigned ascii number l_total_12 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[12]
                                         else
                                             agqmaster:total[12]

define unsigned ascii number l_total_13 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[13]
                                         else
                                             agqmaster:total[13]

define unsigned ascii number l_total_14 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[14]
                                         else
                                             agqmaster:total[14]

define unsigned ascii number l_total_15 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[15]
                                         else
                                             agqmaster:total[15]

define unsigned ascii number l_total_19 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:total[19]
                                         else
                                             agqmaster:total[19]

define unsigned ascii number l_other_totals_3 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:other_totals[3]
                                         else
                                             agqmaster:other_totals[3]

define unsigned ascii number l_other_totals_4 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:other_totals[4]
                                         else
                                             agqmaster:other_totals[4]

define unsigned ascii number l_other_totals_9 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:other_totals[9]
                                         else
                                             agqmaster:other_totals[9]

define unsigned ascii number l_other_totals_18 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:other_totals[18]
                                         else
                                             agqmaster:other_totals[18]

define unsigned ascii number l_other_totals_19 = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:other_totals[19]
                                         else
                                             agqmaster:other_totals[19]

define unsigned ascii number l_terrorism_premium = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:terrorism_premium
                                         else
                                             agqmaster:terrorism_premium

define unsigned ascii number l_surcharge = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                             alt_agqmastsupp:surcharge
                                         else
                                             agqmaster:surcharge

define unsigned ascii number l_liability[8] = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                                  alt_agqmastsupp:liability
                                              else
                                                  agqmaster:liability

define unsigned ascii number l_um_uim_limit_1[8] = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                                  alt_agqmastsupp:um_uim_limit[1]
                                              else
                                                  agqmaster:um_uim_limit[1]

define unsigned ascii number l_um_uim_limit_2[8] = if alt_sfsline:lob_code one of "CPORTFOLIO" then
                                                  alt_agqmastsupp:um_uim_limit[2]
                                              else
                                                  agqmaster:um_uim_limit[2]

define unsigned ascii number l_vehicle_total[8] = l_total_1 +
                                               l_total_2 +
                                               l_total_3 +
                                               l_total_7 +
                                               l_total_8 +
                                               l_total_9 +
                                               l_total_10 +
                                               l_total_14 +
                                               l_total_15 +
                                               l_other_totals_18 +
                                               l_pip_total

--define string l_city = trun(agqvehicle:city) + ", " + agqvehicle:str_state
                                 
define file alt_sfsagent = access sfsagent, set
sfsagent:company_id= agqvehicle:company_id,
sfsagent:agent_no =agqvehicle:agent_no, generic

define file alt_sfscomun = access sfscomun, set
sfscomun:company_id = agqvehicle:company_id,
sfscomun:commercial_underwriter= alt_sfsagent:commercial_underwriter, generic

define file alt_agqend1 = access agqend1, set
agqend1:app_no = agqvehicle:app_no,
agqend1:vehicle_no = agqvehicle:vehicle_no, generic
  
define file alt_sfsemail = access sfsemail, set 
sfsemail:company_id = agqvehicle:company_id,
sfsemail:user_id    = username, generic

define file alt_sfsfob = access sfsfob, set
            sfsfob:company_id = agqvehicle:company_id,
            sfsfob:form_of_business = agqmaster:form_of_business, generic
                   
where agqvehicle:app_no = agqprint1:app_no
list
/nobanner
/domain="agqvehicle"
/nodefaults
/noheadings
/pagewidth=255
/pagelength=0
/duplicates    
/noblanklines                         
         
box/noblanklines/noheadings 

if agqvehicle:vehicle_totals[19] <> 0 then
    {
    "VEHICLE COVERAGES"/newline=2/column=15
    }
     
if agqvehicle:vehicle_totals[1] <> 0 then
    {
    l_liability/column=1/mask="$$,$$$,$$$" 
    "Liability Limit"
    agqvehicle:vehicle_totals[1]/newline/column=50
    if agqvehicle:additional_insured = "Y" then
        "Additional Insured Lessor"/newline/column=12
    if agqpip:limitation = "Y" then
        "Eliminate Verbal Threshold"/newline/column=12
    }
                         
if (agqvehicle:vehicle_totals[2] <> 0 or
   (agqvehicle:type = 1 and
   agqvehicle:state not one of 37)) then
    {
    agqvehicle:medical_payments/column=1/mask="$$,$$$,$$$"
    "Medical Payments"
    agqvehicle:vehicle_totals[2]/newline/column=50
    }
 
if agqvehicle:vehicle_totals[3] <> 0 then
    {
    l_um_uim_limit_1/column=1/mask="$$,$$$,$$$"
    "Uninsured Motorists"
    agqvehicle:vehicle_totals[3]/newline/column=50 
    if agqvehicle:state = 37 then   
        {
        l_um_uim_limit_2/column=1/mask="$$,$$$,$$$"
        "Underinsured Motorists"
        agqvehicle:vehicle_totals[17]/newline/column=50
        }
    }
     
if agqvehicle:vehicle_totals[7] <> 0 then
    {          
    if agqvehicle:comp_deductible = 1 then
        "Full"/column=7
    if agqvehicle:comp_deductible <> 1 then
        agqvehicle:comp_deductible/column=1/mask="$$,$$$,$$$" 
    "Comprehensive Deductible"         
    agqvehicle:vehicle_totals[7]/column=50/newline
    if l_antitheft <> "" then
        l_antitheft/newline/column=12 
    }
     
if agqvehicle:vehicle_totals[8] <> 0 then
    {
    agqvehicle:coll_deductible/column=1/mask="$$,$$$,$$$"
    "Collision Deductible"
    agqvehicle:vehicle_totals[8]/column=50/newline
    if l_dumping <> "" then
        l_dumping/newline/column=12
    if l_safety <> "" then
        l_safety/newline/column=12 
    }

if agqvehicle:vehicle_totals[9] <> 0 then
    {
    "Rental"/column=12
    agqvehicle:rental_days/column=20 
    "Rental Amount:"/column=25
    agqvehicle:rental_amount/column=42
    agqvehicle:vehicle_totals[9]/newline/column=50
    }

if agqvehicle:vehicle_totals[10] <> 0 then  
    {
    "Towing"/column=12
    agqvehicle:vehicle_totals[10]/newline/column=50
    }
          
if agqvehicle:vehicle_totals[13] <> 0 then
    {
    "Medical Expense Benefits"/column=12 
    agqvehicle:vehicle_totals[13]/newline/column=50
    "Motor Bus Passengers"/column=17/newline
    }

if agqpip:pedestrian = "Y" then
    {
    "Pedestrian PIP"/column=12
    agqvehicle:vehicle_totals[4]/newline/column=50
    }

if agqvehicle:vehicle_totals[5] <> 0 then
    {
    "Basic PIP"/column=12
    agqvehicle:vehicle_totals[5]/column=50/newline
    if agqvehicle:type = 2 then
        {
        if agqvehicle:non_employee = "N" then
            "Principally operated by employees"/column=12/newline
        else
            "Principally operated by non-employees"      
        }
    }
if agqvehicle:vehicle_totals[6] <> 0 then
    {    
    if agqvehicle:state = 37 then
        {
        if agqpanofault:combined_option = 1 then
            {
            agqpanofault:combined_limit/column=1
            "Combined PIP"/column=12
            }
        else
            {
            "Additional PIP"/column=12
            }
        } 

    if agqvehicle:state not one of 37 then
        "Additional PIP"/column=12

    if agqpip:additional_pip_option <> 0 then
        {
        "Option"
        agqpip:additional_pip_option
        } 
    agqvehicle:vehicle_totals[6]/column=50/newline
    if agqpanofault:combined_option = 0 and
       agqvehicle:state = 37 then
        {
        "Medical Expense:"/column=5
        agqpanofault:medical_expense_limit/column=20
        "Work Loss:"/column=30
        box/noblanklines/noheadings/squeeze
        agqpanofault:work_loss_monthly_limit/column=40
        "/"
        agqpanofault:work_loss_total_limit 
        end box/newline

        "Funeral Expense:"/column=5
        agqpanofault:funeral_limit/column=20
        "Accidental Death:"/column=30
        agqpanofault:accident_limit/newline/column=40
        }
    }
if agqvehicle:vehicle_totals[11] <> 0 then
    {
    if agqvehicle:state = 37 then                
        {
        agqpanofault:extra_medical_limit/column=1
        "Extraordinary Medical Benefits"/column=12
        }
    else
        {
        "Extended Medical - PIP"/column=12
        }
    agqvehicle:vehicle_totals[11]/column=50/newline
    }

end box

followed by

"Optional Endorsements"/newline/column=1

followed by

if agqend1:app_no = agqvehicle:app_no and
   agqend1:vehicle_no = agqvehicle:vehicle_no then
    box/noblanklines/noheading
    agqend1:code/column=1
    agqend1:description[1,75]/column=10
    agqend1:premium/column=55/mask="ZZZ,ZZZ-"
    end box/newline
     
sorted by agqvehicle:app_no
          agqvehicle:vehicle_no

top of agqvehicle:vehicle_no 
agqvehicle:vehicle_no
agqvehicle:year/column=8 
agqvehicle:make + " " + agqvehicle:model/column=15/newline
"SERIAL NUMBER"/column=6
agqvehicle:serial_no/column=50/newline
"ORIGINAL COST/AGE"/column=6
if agqvehicle:original_cost <> 0 then
    {
    agqvehicle:original_cost/column=48 
    "/"
    agqvehicle:age/newline  
    }
if agqvehicle:original_cost = 0 then
    {
    "N/A"/column=50/newline
    }
"VEHICLE TYPE"/column=6
castype:description/column=50/newline
"CLASS CODE"/column=6
if agqmaster:non_fleet = "F" and
   agqvehicle:company_id = "FARMERS" then
    box/noblanklines/noheading/column=1
    l_class/column=50/mask="99999"
    "Fleet"/column=56
    end box/newline
else
    box/noblanklines/noheading/column=1
    l_class/column=50/mask="99999"
    end box/newline
"STATE"/column=6
sfsstate:description/column=50/newline/Toggle
"COUNTY"/column=6
sfsstate_alias:description/column=50/newline/Toggle
"TERRITORY"/column=6
agqvehicle:territory/column=50
agqvehicle:territory_description/newline=2 

end of agqvehicle:vehicle_no 
if agqvehicle:vehicle_totals[19] <> 0 then
    {
    "VEHICLE"/column=1
    agqvehicle:vehicle_no/column=9
    "TOTAL PREMIUM"/column=15
    agqvehicle:vehicle_totals[19] + agqvehicle:vehicle_totals[14]/column=50/newline=2
    }

end of report
if l_total_11 <> 0 then
    {
    "Non-ownership Liability"/column=1/newline
    "Number of Employees:"/column=5
    agqnonowned:no_employees/column=29
    l_total_11/column=47/newline=2
    }
if l_total_12 <> 0 then
    {
    "Hired Car"/column=1/newline
    "Liability"/column=5
    l_liability/column=30/mask="$$,$$$,$$$"/newline
    if agqnonowned:if_any = "N" and
       agqnonowned:cost_of_hire <> 0 then
        {
        "Cost of Hire:"/column=10
        agqnonowned:cost_of_hire/column=30/mask="$$,$$$,$$$"
        l_other_totals_3/column=47/newline/mask="ZZ,ZZZ,ZZZ.99"
        }
    if agqnonowned:if_any = "Y" then
        { 
        "If Any"/column=10
        l_other_totals_3/column=47/newline/mask="ZZ,ZZZ,ZZZ.99"
        } 
    if agqnonowned:comp_deductible <> 0 or
       agqnonowned:coll_deductible <> 0 then
        {
        ""/newline
        "Physical Damage"/column=5/newline
        if agqnonowned:cost_of_hire_1 <> 0 then
            {
            "Cost of Hire:"/column=10
            agqnonowned:cost_of_hire_1/column=30/mask="$$,$$$,$$$"
            l_other_totals_4/column=47/newline/mask="ZZ,ZZZ,ZZZ.99" 
            }
        else
            {
            "If Any"/column=10
            l_other_totals_4/column=47/newline/mask="ZZ,ZZZ,ZZZ.99" 
            }
        }
    if agqnonowned:comp_deductible <> 0 then
        {
        "Comp Deductible:"/column=10
        if agqnonowned:comp_deductible = 1 then
            {
            "Full"/newline/column=37
            }
        else                        
            {
            agqnonowned:comp_deductible/newline/column=30/mask="$$,$$$,$$$"
            }
        }                                            
    if agqnonowned:coll_deductible <> 0 then
        {
        "Coll Deductible:"/column=10
        agqnonowned:coll_deductible/newline/column=30/mask="$$,$$$,$$$"
        }
    if agqnonowned:funeral_medical_payments = "Y" then
        {
        "Non-owned/Hired Car Funeral Director Medical Payments"/column=5
        l_other_totals_19/column=47/newline
        }
    }
if l_total_4 <> 0 then
    {
    "Drive Other Car"/column=1
    l_total_4/column=47/newline
    "Liability:"/column=5
    agqdoc:liability/newline/column=25/mask="$$,$$$,$$$"
    "Uninsured:"/column=5
    agqdoc:um_uim_limit/newline/column=25/mask="$$,$$$,$$$"  
    "Underinsured:"/column=5
    agqdoc:um_uim_limit_2/newline/column=25/mask="$$,$$$,$$$"
    "Medical Payments"/column=5
    agqdoc:medical_payments/newline/column=25/mask="$$,$$$,$$$"
    "Include Comp:"/column=5
    agqdoc:comp/newline/column=32
    "Include Coll:"/column=5
    agqdoc:coll/newline/column=32 
    }

if l_other_totals_9 <> 0 then
    {
    "Broadened PIP"/column=1
    l_other_totals_9/column=47/newline
    }          
 
if l_total_15 <> 0 then
    {
    "Miscellaneous"/column=1
    l_total_15/column=47/newline
    agqmisc:description/column=5/newline 
    }                           

if agqdev:app_no = agqvehicle:app_no then
    { 
    if agqdev:experience <> 0 then
        {
        "Experience Factor - Physical Damage"/column=1
        agqdev:experience[1]/column=40 
        "Liability"/column=50
        agqdev:experience[2]
        "Other"/column=70
        agqdev:experience[3]/newline
        }
    if agqdev:schedule <> 0 then
        {
        "Schedule Factor   - Physcial Damage  "/column=1
        agqdev:schedule[1]/column=40
        "Liability"/column=50
        agqdev:schedule[2]
        "Other"/column=70
        agqdev:schedule[3]/newline
        }

    box/noblanklines/headings/squeeze
    if agqdev:deviation_str[1] <> "" then
        {
        agqdev:deviation_str[1]/column=1/noheading 
        agqdev:deviation[1]/noheading           
        }
    if agqdev:deviation_str[2] <> "" then
        {
        agqdev:deviation_str[2]/noheading
        agqdev:deviation[2]/noheading
        }
    if agqdev:deviation_str[3] <> "" then
        {
        agqdev:deviation_str[3]/noheading
        agqdev:deviation[3]/noheading
        }
    if agqdev:deviation_str[4] <> "" then
        {
        agqdev:deviation_str[4]/noheading
        agqdev:deviation[4]/noheading
        }
    if agqdev:deviation_str[5] <> "" then
        {
        agqdev:deviation_str[5]/noheading
        agqdev:deviation[5]/noheading 
        }                            
    end box/newline

    if agqdev:package_policy_no <> "" then
        {
        "Package Policy:"/column=1
        agqdev:package_policy_no/newline/column=22
        }

    }                                

if agqdev:companion_discount = 1 then 
    {
    ""/newline
    "COMPANION POLICY NO: "/column=1
    agqdev:companion_policy_no/column=22/mask="ZZZZZZZZZ"
    "EFF DATE:"/column=40
    agqdev:companion_eff_date/column=50
    }

""/newline=2     
if l_total_1 <> 0 or
   l_total_2 <> 0 or
   l_total_3 <> 0 or
   l_total_7 <> 0 or 
   l_total_8 <> 0 or
   l_pip_total <> 0 or
   l_total_9 <> 0 or
   l_total_10 <> 0 or
   l_total_14 <> 0 or
   l_total_15 <> 0 then
    { 
    "PREMIUM SUMMARY"/column=1/newline=2
    }
if l_total_1 <> 0 then
    {
    "Total Liability"/column=5
    l_total_1/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }                         
if l_total_2 <> 0 then
    {
    "Total Medical Payments"/column=5
    l_total_2/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_3 <> 0 then
    {
    "Total Uninsured Motorists"/column=5
    l_total_3/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    if agqvehicle:state = 37 then
        {
        "Total Underinsured Motorists"/column=5
        l_other_totals_18/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
        }
    }
if l_total_7 <> 0 then
    {
    "Total Comprehensive"/column=5
    l_total_7/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_8 <> 0 then
    {
    "Total Collision"/column=5
    l_total_8/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_pip_total <> 0 then
    {
    "Total PIP"/column=5
    l_pip_total/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_9 <> 0 then
    {
    "Total Rental"/column=5
    l_total_9/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_10 <> 0 then
    {
    "Total Towing"/column=5
    l_total_10/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_14 <> 0 then
    {
    "Total Optional Endorsements"/column=5
    l_total_14/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_15 <> 0 then
    {
    "Total Miscellaneous"/column=5
    l_total_15/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }

""/newline=2
if l_vehicle_total <> 0 then
    {
    "VEHICLE TOTALS"/column=1
    l_vehicle_total/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_4 <> 0 or
   l_other_totals_9 <> 0 then
    {
    "DOC & BROADENED PIP"/column=1
    l_total_4 + l_other_totals_9/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
    }
if l_total_11 <> 0 or
   l_total_12 <> 0 then
    {
    "HIRED/NONOWNED AUTO"
    l_total_11 + l_total_12/column=47/newline=2/mask="Z,ZZZ,ZZZ.99-"
    }

"TOTAL"/column=1
l_total_19/mask="Z,ZZZ,ZZZ.99-"/newline/column=47
"TERRORISM"/column=1
l_terrorism_premium/column=47/newline/mask="Z,ZZZ,ZZZ.99-"

"FINAL TOTAL"/column=1
l_total_19 + l_terrorism_premium/column=47/newline/mask="Z,ZZZ,ZZZ.99-"
if l_surcharge <> 0 then
    {
    "SURCHARGE"/column=1
    l_surcharge/column=47/mask="Z,ZZZ,ZZZ.99-"/newline=2
    }

""/newline=2
todaysdate/heading="DATE PRINTED"
username/column=40/heading="PRINTED BY"/newline
if sfsemail:agent_no = 0 then
    alt_sfscomun:name/heading="UNDERWRITER"/column=1

top of report
sfscompany:name[1]/column=30/newline
if agqvehicle:line_of_business = 16 then
    "PREMIER"/newline=2/column=42

"APP NO:"/column=1
agqvehicle:app_no/column=15/mask="ZZZZZZZZZZZ"
              
box/noblanklines/noheadings
"NAME:"/column=25
include "renaeq2.inc"/newline
IF (POS("=",I_NAME_1)) <> 0 THEN
        I_REV_NAME_1
ELSE
        I_NAME_1/newline/column=31
IF (POS("=",I_NAME_2)) <> 0 THEN
        I_REV_NAME_2
ELSE
        I_NAME_2/newline/column=31
--agqvehicle:address[1]/newline/column=31
--agqvehicle:address[2]/newline/column=31
--agqvehicle:address[3]/newline/column=31
--box/noblanklines/squeeze/column=31
--l_city
--agqvehicle:str_zipcode/newline
--end box
end box/newline

"EFFECTIVE DATE: "/column=1
agqvehicle:eff_date 
"EXPIRATION DATE: "/column=50
agqvehicle:exp_date/newline=2

box/noblanklines/noheadings/column=1
alt_sfsagent:name[1]/column=1/newline
alt_sfsagent:name[2]/column=1/newline
alt_sfsagent:name[3]/column=1/newline
alt_sfsagent:address[1]/column=1/newline
alt_sfsagent:address[2]/column=1/newline
alt_sfsagent:address[3]/column=1/newline
box/noblanklines/noheadings/squeeze/column=1
alt_sfsagent:city + ","/column=1
alt_sfsagent:str_state
if alt_sfsagent:zipcode[1,4] = 0 then
    {
    alt_sfsagent:zipcode/mask="9999"
    }
else
    {
    alt_sfsagent:zipcode/mask="99999-9999"/newline
    }
alt_sfsagent:telephone[1]/column=1
end box
end box/newline=2

