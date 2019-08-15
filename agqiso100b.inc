/* agqiso100b.inc

   scips.com

   april 20, 2006

   liability worksheet
*/

writefile(l_dec,"%s",trun(l_arial))
if agqliability:app_no = agqprint1:app_no then
    begin
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","LIABILITY")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")
    end

access agqliablimits1, set agqliablimits1:app_no = agqliability:app_no, generic

access agqliabdeduct, set agqliabdeduct:app_no = agqliability:app_no, generic

writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s","General Aggregate:")
writefile(l_dec,"%s","<033>&a1500h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(agqliablimits1:general_aggregate,"ZZZ,ZZZ,ZZ9"))
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s","Products/Completed Operations:")
writefile(l_dec,"%s","<033>&a4500h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(agqliablimits1:products,"ZZZ,ZZZ,ZZ9"))
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<NL>")
writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s","Each Occurrence:")
writefile(l_dec,"%s","<033>&a1500h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(agqliablimits1:occurrence,"ZZZ,ZZZ,ZZ9"))
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s","Personal and Advertising Injury:")
writefile(l_dec,"%s","<033>&a4500h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(agqliablimits1:advertising_personal_injury,"ZZZ,ZZZ,ZZ9"))
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<NL>")
writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s","Damage to Premises:")
writefile(l_dec,"%s","<033>&a1500h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(agqliablimits1:fire_legal,"ZZZ,ZZZ,ZZ9"))
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s","Medical Expense (Any one Person):")
writefile(l_dec,"%s","<033>&a4500h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(agqliablimits1:medical_payments,"ZZZ,ZZZ,ZZ9"))
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","<NL>")
writefile(l_dec,"%s","<NL>")

l_total = 0
while agqliability:app_no = agqprint1:app_no
    begin
    l_total_1 = 0
    l_total = l_total +
              agqliability:prem[1] +
              agqliability:prem[2] +
              agqliability:minimum_premium_adjustment[1] +
              agqliability:minimum_premium_adjustment[2]
    l_total = l_total + 
              agqliability:total_endorsements +
              agqliability:fire_legal_premium +
              agqliability:total_misc 
    access agqlocation, set agqlocation:app_no = agqliability:app_no,
                            agqlocation:prem_no  = agqliability:prem_no,
                            agqlocation:build_no = agqliability:build_no, generic

    l_state        = agqliability:state
    l_county       = agqliability:county
    l_lob          = agqliability:rating_line_of_business
    l_alpha_look   = agqliability:class_description
    access sfsstate, set sfsstate:company_id = agqname:company_id,
                         sfsstate:state      = l_state,
                         sfsstate:county     = "00", generic

    access sfsstate_alias, set sfsstate_alias:company_id = agqname:company_id,
                               sfsstate_alias:state      = l_state,
                               sfsstate_alias:county     = l_county, generic

    access cpsclass, set cpsclass:company_id       = agqname:company_id,
                         cpsclass:state            = l_state,
                         cpsclass:line_of_business = l_lob,
                         cpsclass:alpha_look       = l_alpha_look, generic

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s","Location:  ",str(agqliability:prem_no,"ZZZZ"))
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s%s","Building:  ",str(agqliability:build_no,"ZZZZ"))
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s",trun(agqlocation:address))
    writefile(l_dec,"%s","<NL>")
    if agqlocation:address1[1] <> "" then
        begin
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s",trun(agqlocation:address1[1]))
        writefile(l_dec,"%s","<NL>")
        end
    if agqlocation:address1[2] <> "" then
        begin
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s",trun(agqlocation:address1[2]))
        writefile(l_dec,"%s","<NL>")
        end
    if agqlocation:address1[3] <> "" then
        begin
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s",trun(agqlocation:address1[3]))
        writefile(l_dec,"%s","<NL>")
        end
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s%s%s%s%s",trun(agqlocation:city),
                                 ", ",
                                 agqlocation:str_state,
                                 " ",
                                 str(agqlocation:zipcode,"99999-9999"))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s%s%s","Business Desc:  ",
                               Trun(agqliability:business_description[1]),
                               " ",
                               trun(agqliability:business_description[2]))
    Writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s%s%s","State:    ",str(agqliability:state)," ",trun(sfsstate:description))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s%s%s","Territory:  ",str(agqliability:territory)," ",str(trun(agqliability:territory_description)))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","PMA:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s",agqliability:type)
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Increased Limits Table:  ")
    writefile(l_dec,"%s","<033>&a1400h+0V")
    writefile(l_dec,"%s",str(agqliability:limits_table))
    writefile(l_dec,"%s","<033>&a1500h+0V")
    writefile(l_dec,"%s",agqliability:products_limit_table)
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Class Code:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s%s%s",str(agqliability:class_code,"ZZZZZ")," ",trun(agqliability:class_description))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")
 
    switch(agqliability:company_rate[1])
      case 1  : l_company_rate = "Yes"
      default : l_company_rate = "No"
      end
    switch(agqliability:company_rate[2])
      case 1  : l_company_rate_1 = "Yes"
      default : l_company_rate_1 = "No"
      end
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s","Exposure")
    writefile(l_dec,"%s","<033>&a1800h+0V")
    writefile(l_dec,"%s","Per")
    writefile(l_dec,"%s","<033>&a2400h+0V")
    writefile(l_dec,"%s","Rate")
    writefile(l_dec,"%s","<033>&a2800h+0V")
    writefile(l_dec,"%s"," Co") 
    writefile(l_dec,"%s","<033>&a3200h+0V")
    writefile(l_dec,"%s","Exposure")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s"," Base")
    writefile(l_dec,"%s","<033>&a2800h+0V")
    writefile(l_dec,"%s","Rate") 
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Prem/Ops:  ")
    writefile(l_dec,"%s","<033>&a1300h+0V")
    writefile(l_dec,"%s",agqliability:exposure_base[1])
    writefile(l_dec,"%s","<033>&a1800h+0V")
    writefile(l_dec,"%s",str(agqliability:rates_per[1],"Z,ZZZ"))
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s",str(agqliability:base_rate[1],"ZZ9.ZZZ"))
    writefile(l_dec,"%s","<033>&a2900h+0V")
    writefile(l_dec,"%s",l_company_rate)
    writefile(l_dec,"%s","<033>&a3200h+0V")
    writefile(l_dec,"%s",str(agqliability:exposure[1],"ZZZ,ZZZ,ZZZ")) 
    writefile(l_dec,"%s","<NL>")

    if agqliability:exposure[2] <> 0 then
        begin
    	writefile(l_dec,"%s","<033>&a300h+0V")
    	writefile(l_dec,"%s","Products:  ")
    	writefile(l_dec,"%s","<033>&a1300h+0V")
    	writefile(l_dec,"%s",agqliability:exposure_base[2])
    	writefile(l_dec,"%s","<033>&a1800h+0V")
    	writefile(l_dec,"%s",str(agqliability:rates_per[2],"Z,ZZZ"))
    	writefile(l_dec,"%s","<033>&a2300h+0V")
    	writefile(l_dec,"%s",str(agqliability:base_rate[2],"ZZ9.ZZZ"))
    	writefile(l_dec,"%s","<033>&a2900h+0V")
    	writefile(l_dec,"%s",l_company_rate_1)
    	writefile(l_dec,"%s","<033>&a3200h+0V")
    	writefile(l_dec,"%s",str(agqliability:exposure[2],"ZZZ,ZZZ,ZZZ")) 
    	writefile(l_dec,"%s","<NL>")
        end
    else
    if agqliability:product_not_applicable = 1 then
        begin
    	writefile(l_dec,"%s","<033>&a300h+0V")
    	writefile(l_dec,"%s","Products Included")
        writefile(l_dec,"%s","<NL>")
        end

    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s","Increased")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Exclusion")
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s","  Limits")
    writefile(l_dec,"%s","<033>&a1300h+0V")
    writefile(l_dec,"%s","  BI Ded")
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","  PD Ded")
    writefile(l_dec,"%s","<033>&a2700h+0V")
    writefile(l_dec,"%s","Loss Cost")
    writefile(l_dec,"%s","<033>&a3400h+0V")
    writefile(l_dec,"%s"," PMA")
    writefile(l_dec,"%s","<033>&a4100h+0V")
    writefile(l_dec,"%s","IRPM")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Factors")
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s","  Factor")
    writefile(l_dec,"%s","<033>&a1300h+0V")
    writefile(l_dec,"%s","  Factor")
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","  Factor")
    writefile(l_dec,"%s","<033>&a2700h+0V")
    writefile(l_dec,"%s","  Factor")
    writefile(l_dec,"%s","<033>&a3400h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a4100h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s",str(agqliability:aggregate_surcharge[1],"ZZZ.999"))
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s",str(agqliability:increase_limits_factor[1],"ZZZ.999"))
    if agqliabdeduct:deductible[1] <> 0 or
       agqliabdeduct:deductible[2] <> 0 or 
       agqliabdeduct:deductible[5] <> 0 or
       agqliabdeduct:deductible[6] <> 0 then
        begin
        Writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqliability:deductible_factor[1],"ZZZ.999"))
        end
    if agqliabdeduct:deductible[3] <> 0 or
       agqliabdeduct:deductible[4] <> 0 or
       agqliabdeduct:deductible[5] <> 0 or
       agqliabdeduct:deductible[6] <> 0 then
        begin
        writefile(l_dec,"%s","<033>&a2000h+0V")
        writefile(l_dec,"%s",str(agqliability:deductible_factor[1],"ZZZ.999"))
        end
    writefile(l_dec,"%s","<033>&a2700h+0V")
    writefile(l_dec,"%s",str(agqliability:loss_cost,"ZZ.999"))
    writefile(l_dec,"%s","<033>&a3400h+0V")
    writefile(l_dec,"%s",str(agqliability:package_mod[1],"ZZ.999"))
    writefile(l_dec,"%s","<033>&a4100h+0V")
    writefile(l_dec,"%s",str(agqliability:company_deviation[1],"ZZ.999"))
    writefile(l_dec,"%s","<NL>")
    if agqliability:exposure[2] <> 0 then
        begin
    	writefile(l_dec,"%s","<033>&a800h+0V")
    	writefile(l_dec,"%s",str(agqliability:increase_limits_factor[2],"ZZZ.999"))
        if agqliabdeduct:deductible[1] <> 0 or
           agqliabdeduct:deductible[2] <> 0 or 
           agqliabdeduct:deductible[5] <> 0 or
           agqliabdeduct:deductible[6] <> 0 then
            begin
            Writefile(l_dec,"%s","<033>&a1300h+0V")
            writefile(l_dec,"%s",str(agqliability:deductible_factor[2],"ZZZ.999"))
            end
        if agqliabdeduct:deductible[3] <> 0 or
           agqliabdeduct:deductible[4] <> 0 or
           agqliabdeduct:deductible[5] <> 0 or
           agqliabdeduct:deductible[6] <> 0 then
            begin
            writefile(l_dec,"%s","<033>&a2000h+0V")
            writefile(l_dec,"%s",str(agqliability:deductible_factor[2],"ZZZ.999"))
            end
    	writefile(l_dec,"%s","<NL>")
        end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a1100h+0V")
    writefile(l_dec,"%s","Rate")
    writefile(l_dec,"%s","<033>&a1650h+0V")
    writefile(l_dec,"%s","   Limit")
    writefile(l_dec,"%s","<033>&a2350h+0V")
    writefile(l_dec,"%s","Premium")
    writefile(l_dec,"%s","<033>&a2900h+0V")
    writefile(l_dec,"%s","   Minimum")
    writefile(l_dec,"%s","<NL>")

    if agqliability:exposure[1] <> 0 then
        begin
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Prem/Ops: ")
        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqliability:adjusted_rate[1],"ZZ9.999"))
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",str(agqliability:exposure[1],"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s",str(agqliability:prem[1],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s",str(agqliability:minimum_premium[1],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        end

    if agqliability:exposure[2] <> 0 then
        begin
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Products: ")
        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqliability:adjusted_rate[2],"ZZ9.999"))
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",str(agqliability:exposure[2],"ZZZ,ZZZ,ZZZ"))
        Writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s",str(agqliability:prem[2],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s",str(agqliability:minimum_premium[2],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        end

    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<033>&a1000h+0V")
    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","Total Premium")
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
    l_total_1 = agqliability:prem[1] + 
                agqliability:prem[2] +
                agqliability:minimum_premium_adjustment[1] +
                agqliability:minimum_premium_adjustment[2]
    writefile(l_dec,"%s",str(l_total_1,"ZZZ,ZZZ.99"))  
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<033>&a1000h+0V")
    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","Damage to Premises Charge")
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
    writefile(l_dec,"%s",str(agqliability:fire_legal_premium,"ZZZ,ZZZ.99"))  
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","FORM EDITION")
    writefile(l_dec,"%s","<033>&a1500h+0V")
    writefile(l_dec,"%s","DESCRIPTION")
    writefile(l_dec,"%s","<033>&a4000h+0V")
    writefile(l_dec,"%s","PREMIUM")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    access agqend, set agqend:app_no = agqliability:app_no,  
                       agqend:prem_no  = agqliability:prem_no, 
                       agqend:build_no = agqliability:build_no, generic

    while agqend:app_no = agqliability:app_no and
          agqend:prem_no  = agqliability:prem_no and
          agqend:build_no = agqliability:build_no
        begin
        if agqend:lob_end_code one of "L" then
            begin
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s",trun(l_arial))
            writefile(l_dec,"%s",agqend:form_edition)
            writefile(l_dec,"%s","<033>&a1500h+0V")
            writefile(l_dec,"%s",agqend:description)
            if agqend:premium <> 0 then 
                begin
                writefile(l_dec,"%s","<033>&a4000h+0V")
                writefile(l_dec,"%s",str(agqend:premium,"ZZZ,ZZZ.99-"))
                end
            else
            if agqend:manual_premium <> 0 then
                begin
                writefile(l_dec,"%s","<033>&a4000h+0V")
                writefile(l_dec,"%s",str(agqend:manual_premium,"ZZZ,ZZZ.99-"))
                end
            writefile(l_dec,"%s","<NL>")
            end

        next agqend
        end
           
    next agqliability
    end

access agqend, set agqend:app_no = agqprint1:app_no, 
                   agqend:prem_no  = 0, 
                   agqend:build_no = 0, generic

while agqend:app_no = agqprint1:app_no and
      agqend:prem_no  = 0 and
      agqend:build_no = 0 
        begin
        if agqend:terrorism_form = 1 and
           agqend:lob_end_code one of "L" then
            l_liability_terror_premium = agqend:premium
        if agqend:lob_end_code one of "L" then
            begin
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s",trun(l_arial))
            writefile(l_dec,"%s",agqend:form_edition)
            writefile(l_dec,"%s","<033>&a1500h+0V")
            writefile(l_dec,"%s",agqend:description)
            if agqend:premium <> 0 then 
                begin
                writefile(l_dec,"%s","<033>&a4000h+0V")
                writefile(l_dec,"%s",str(agqend:premium,"ZZZ,ZZZ.99-"))
                end
            else
            if agqend:manual_premium <> 0 then
                begin
                writefile(l_dec,"%s","<033>&a4000h+0V")
                writefile(l_dec,"%s",str(agqend:manual_premium,"ZZZ,ZZZ.99-"))
                end
            writefile(l_dec,"%s","<NL>")
            end

        next agqend
        end

writefile(l_dec,"%s","<NL>")
writefile(l_dec,"%s","<033>&a1300h+0V")
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","Total Liability Premium")
writefile(l_dec,"%s","<033>&a2300h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(l_total_5,"ZZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
writefile(l_dec,"%s","<033>&a1300h+0V")
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","Terrorism Premium")
writefile(l_dec,"%s","<033>&a2300h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(l_liability_terror_premium,"ZZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
writefile(l_dec,"%s","<033>&a1300h+0V")
writefile(l_dec,"%s",trun(l_arial))
writefile(l_dec,"%s","Final Liability Total")
writefile(l_dec,"%s","<033>&a2300h+0V")
writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
writefile(l_dec,"%s",str(l_total_5 +
                         l_liability_terror_premium,"ZZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
