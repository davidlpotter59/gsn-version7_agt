/* agqmso100a.inc

   scips.com

   april 11, 2006

   property worksheet
*/

if agqgeneral1:app_no = agqprint1:app_no then
    begin
    Writefile(l_dec,"%s",trun(l_arial_bold))
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","PROPERTY")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")
    end

while agqgeneral1:app_no = agqprint1:app_no
    begin
    access agqlocation, set agqlocation:app_no   = agqgeneral1:app_no,
                            agqlocation:prem_no  = agqgeneral1:prem_no,
                            agqlocation:build_no = agqgeneral1:build_no, generic

    l_state        = agqgeneral1:state
    l_county       = agqgeneral1:county
    l_lob          = agqgeneral1:rating_line_of_business
    l_rate_type    = agqgeneral1:rate_type
    l_construction = agqgeneral1:construction
    l_form         = agqgeneral1:form
    l_alpha_look   = agqgeneral1:description
    access sfsstate, set sfsstate:company_id = agqname:company_id,
                         sfsstate:state      = l_state,
                         sfsstate:county     = "00", generic

    access sfsstate_alias, set sfsstate_alias:company_id = agqname:company_id,
                               sfsstate_alias:state      = l_state,
                               sfsstate_alias:county     = l_county, generic

    access cpsratetype, set cpsratetype:company_id       = agqname:company_id,
                            cpsratetype:state            = l_state,
                            cpsratetype:line_of_business = l_lob,
                            cpsratetype:rate_type        = l_rate_type, generic

    access sfsconstruction, set sfsconstruction:company_id       = agqname:company_id,
                                sfsconstruction:state            = l_state,
                                sfsconstruction:line_of_business = l_lob,
                                sfsconstruction:construction     = l_construction, generic

    access sfsform, set sfsform:company_id       = agqname:company_id,
                        sfsform:state            = l_state,
                        sfsform:line_of_business = l_lob,
                        sfsform:policy_form      = l_form, generic

    access cpsclass, set cpsclass:company_id       = agqname:company_id,
                         cpsclass:state            = l_state,
                         cpsclass:line_of_business = l_lob,
                         cpsclass:alpha_look       = l_alpha_look, generic

    if agqgeneral1:blanket = 0 then
        begin
    	writefile(l_dec,"%s",trun(l_arial))
    	writefile(l_dec,"%s","<033>&a300h+0V")
    	writefile(l_dec,"%s%s","Location:  ",str(agqgeneral1:prem_no,"ZZZZ"))
    	writefile(l_dec,"%s","<033>&a1000h+0V")
    	writefile(l_dec,"%s%s","Building:  ",str(agqgeneral1:build_no,"ZZZZ"))
        end
    else
        begin
    	writefile(l_dec,"%s",trun(l_arial))
    	writefile(l_dec,"%s","<033>&a300h+0V")
    	writefile(l_dec,"%s","Blanketed Quote")
        end
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
                               trun(agqgeneral1:business_desc[1]),
                               " ",
                               trun(agqgeneral1:business_desc[2]))
    Writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s%s%s","State:  ",str(agqgeneral1:state)," ",trun(sfsstate:description))
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s%s%s%s","County:  ",str(agqgeneral1:county)," ",trun(sfsstate_alias:description))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s","Community:  ",agqgeneral1:community)
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Rate Type:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    if agqgeneral1:blanket = 0 then
    	begin 
        writefile(l_dec,"%s%s%s",str(agqgeneral1:rate_type),
                                 " ",
                                 cpsratetype:description)
        end
    else
        begin
        writefile(l_dec,"%s","Blanket")
        end 
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Form:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s%s%s",str(agqgeneral1:form),
                             " ",
                             trun(sfsform:description))

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","PMA:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    writefile(l_dec,"%s",agqgeneral1:type)
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Class Code:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    if agqgeneral1:blanket = 1 then
        writefile(l_dec,"%s","Blanket Rated")
    else
        writefile(l_dec,"%s%s%s",str(agqgeneral1:class_code,"ZZZZ")," ",trun(cpsclass:alpha_look))
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Construction:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s%s%s",str(agqgeneral1:construction),
                             " ",
                             trun(sfsconstruction:description))

    writefile(l_dec,"%s","<033>&a2500h+0V")
    writefile(l_dec,"%s","Reinforced: ")
    switch(agqgeneral1:reinforced)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","N/A")
      end
    writefile(l_dec,"%s","<033>&a3500h+0V")
    writefile(l_dec,"%s","Light Steel: ")
    switch(agqgeneral1:steel)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","N/A")
      end
    writefile(l_dec,"%s","<033>&a4500h+0V")
    writefile(l_dec,"%s","High Rise: ")
    switch(agqgeneral1:high)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","N/A")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Rate Group:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:rate_group))

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Exclude VMM:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:vmm_exclusion)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Protection:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:protection))

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Exclude Wind/Hail:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:exclusions)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","BCEG Individual:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    switch(agqgeneral1:bceg_individual)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s%s","  ",str(agqgeneral1:bceg))

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Sprinklered:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:sprinklered)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Deductible:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:deductible,"ZZZZZ"))

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Replacement Cost:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:replacement_cost)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Coinsurance:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:coinsurance))

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Exclude Theft:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:theft)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Inflation Guard:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s%s",str(agqgeneral1:inflation_guard),"%")

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Blanket:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:blanket)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Symbol:  ")
    writefile(l_dec,"%s","<033>&a1200h+0V")
    writefile(l_dec,"%s%s",str(agqgeneral1:symbol),str(agqgeneral1:symbol_number))

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Agreed Value:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:agreed_value)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")

/*    if sfsemail:agent_no = 0 then
        begin
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Crime Limit:  ")
        writefile(l_dec,"%s","<033>&a1200h+0V")
        writefile(l_dec,"%s",str(agqgeneral1:crime_limit,"ZZ,ZZZ,ZZZ"))
        end*/

    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s","Boilers:  ")
    writefile(l_dec,"%s","<033>&a3300h+0V")
    switch(agqgeneral1:boilers)
      case 1  : writefile(l_dec,"%s","Yes")
      default : writefile(l_dec,"%s","No")
      end
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Protection")
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s","Territory")
    writefile(l_dec,"%s","<033>&a1300h+0V")
    writefile(l_dec,"%s","Coinsurance")
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","Deductible")
    writefile(l_dec,"%s","<033>&a2700h+0V")
    writefile(l_dec,"%s","Inflation")
    writefile(l_dec,"%s","<033>&a3400h+0V")
    writefile(l_dec,"%s","Loss Cost")
    writefile(l_dec,"%s","<033>&a4100h+0V")
    writefile(l_dec,"%s","PMA")
    writefile(l_dec,"%s","<033>&a4600h+0V")
    writefile(l_dec,"%s","IRPM")
    writefile(l_dec,"%s","<033>&a5200h+0V")
    writefile(l_dec,"%s","Location")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a1300h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a2700h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a3400h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a4100h+0V")
    writefile(l_dec,"%s","Factor")
    writefile(l_dec,"%s","<033>&a5200h+0V")
    writefile(l_dec,"%s","Credit")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:protection_factor,"ZZ.999"))
    writefile(l_dec,"%s","<033>&a800h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:rating_territory_factor,"ZZ.999"))
    writefile(l_dec,"%s","<033>&a1300h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:coinsurance_factor[1],"ZZ.999"))
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:deductible_factor[1],"ZZ.999"))
    writefile(l_dec,"%s","<033>&a2700h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:inflation_factor[1],"ZZ.999"))
    writefile(l_dec,"%s","<033>&a3400h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:loss_cost,"ZZ.999"))
    writefile(l_dec,"%s","<033>&a4100h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:package_mod[1],"ZZ.999"))
    writefile(l_dec,"%s","<033>&a4600h+0V")
    writefile(l_dec,"%s",str(agqgeneral1:company_deviation[1],"ZZ.999"))
    writefile(l_dec,"%s","<033>&a5200h+0V")
    if sfsline:lob_code one of "CPORTFOLIO" then
        writefile(l_dec,"%s",str(agqmastsupp:irpm,"ZZ.99"))
    else
        writefile(l_dec,"%s",str(agqmaster:irpm,"ZZ.99"))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    if agqgeneral1:limit[1] <> 0 then
        begin
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        if agqgeneral1:blanket = 0 then
       	    begin
            writefile(l_dec,"%s",cpsratetype:description)
            end
        else
            begin
            writefile(l_dec,"%s","Blanket Limit:")
            end
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqgeneral1:limit[1],"ZZZ,ZZZ,ZZ9"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s","Rate")
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s","New Rate")
        writefile(l_dec,"%s","<033>&a2350h+0V")
        writefile(l_dec,"%s","Mod Rate")
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s","Limit")
        writefile(l_dec,"%s","<033>&a3500h+0V")
        writefile(l_dec,"%s","Premium")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Group I")
        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqgeneral1:base_rate[1],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqgeneral1:new_rate[1],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a2200h+0V")
        writefile(l_dec,"%s",str(agqgeneral1:adj_rate[1],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a2700h+0V")
        writefile(l_dec,"%s",str(agqgeneral1:limit[1] divide 100,"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a3500h+0V")
        l_premium_1 = ((agqgeneral1:limit[1] divide 100) *
                      agqgeneral1:adj_rate[1]) 
        writefile(l_dec,"%s",str(l_premium_1,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Group II")
        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqgeneral1:base_rate[2],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqgeneral1:new_rate[2],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a2200h+0V")
        writefile(l_dec,"%s",str(agqgeneral1:adj_rate[2],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a2700h+0V")
        writefile(l_dec,"%s",str(agqgeneral1:limit[1] divide 100,"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a3500h+0V")
        writefile(l_dec,"%s",str(agqgeneral1:premium[2],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")

        if agqgeneral1:form > 1 then
            begin
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s",trun(l_arial))
            switch(agqgeneral1:form)
              case 2 : writefile(l_dec,"%s","Broad")
              case 3 : writefile(l_dec,"%s","Special")
              end
            writefile(l_dec,"%s","<033>&a1100h+0V")
            writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
            writefile(l_dec,"%s",str(agqgeneral1:base_rate[3],"ZZ.999"))
            writefile(l_dec,"%s","<033>&a1650h+0V")
            writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
            writefile(l_dec,"%s",str(agqgeneral1:new_rate[3],"ZZ.999"))
            writefile(l_dec,"%s","<033>&a2200h+0V")
            writefile(l_dec,"%s",str(agqgeneral1:adj_rate[3],"ZZ.999"))
            writefile(l_dec,"%s","<033>&a2700h+0V")
            writefile(l_dec,"%s",str(agqgeneral1:limit[1] divide 100,"ZZZ,ZZZ,ZZZ"))
            writefile(l_dec,"%s","<033>&a3500h+0V")
            writefile(l_dec,"%s",str(agqgeneral1:premium[3],"ZZZ,ZZZ.99"))
            writefile(l_dec,"%s","<NL>")

            if agqgeneral1:rate_type not one of 1 then
                begin
                writefile(l_dec,"%s","<033>&a300h+0V")
                writefile(l_dec,"%s",trun(l_arial))
                writefile(l_dec,"%s","Theft")
                writefile(l_dec,"%s","<033>&a1100h+0V")
                writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
                writefile(l_dec,"%s",str(agqgeneral1:base_rate[4],"ZZ.999"))
                writefile(l_dec,"%s","<033>&a1650h+0V")
                writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
                writefile(l_dec,"%s",str(agqgeneral1:new_rate[4],"ZZ.999"))
                writefile(l_dec,"%s","<033>&a2200h+0V")
                writefile(l_dec,"%s",str(agqgeneral1:adj_rate[4],"ZZ.999"))
                writefile(l_dec,"%s","<033>&a2700h+0V")
                writefile(l_dec,"%s",str(agqgeneral1:limit[1] divide 100,"ZZZ,ZZZ,ZZZ"))
                writefile(l_dec,"%s","<033>&a3500h+0V")
                writefile(l_dec,"%s",str(agqgeneral1:premium[4],"ZZZ,ZZZ.99"))
                writefile(l_dec,"%s","<NL>")
                end
            end

        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a2200h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Total Premium")
        writefile(l_dec,"%s","<033>&a3500h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(l_premium_1 +
                                 agqgeneral1:premium[2] +
                                 agqgeneral1:premium[3] +
                                 agqgeneral1:premium[4],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a2200h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Boiler & Machinery")
        writefile(l_dec,"%s","<033>&a3500h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqgeneral1:boilers_premium,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")
        end

    access agqend, set agqend:app_no = agqgeneral1:app_no,  
                       agqend:prem_no  = agqgeneral1:prem_no, 
                       agqend:build_no = agqgeneral1:build_no, generic

    while agqend:app_no = agqgeneral1:app_no and
          agqend:prem_no  = agqgeneral1:prem_no and
          agqend:build_no = agqgeneral1:build_no
        begin
        if agqend:lob_end_code one of "P" then
            l_property = "Y"

	next agqend
        end

    if l_property = "Y" then
        begin
   	writefile(l_dec,"%s","<033>&a100h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","FORM EDITION")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s","DESCRIPTION")
        writefile(l_dec,"%s","<033>&a4200h+0V")
        writefile(l_dec,"%s","PREMIUM")
        writefile(l_dec,"%s","<NL>")
	end

    access agqend, set agqend:app_no   = agqgeneral1:app_no,  
                       agqend:prem_no  = agqgeneral1:prem_no, 
                       agqend:build_no = agqgeneral1:build_no, generic

    while agqend:app_no   = agqgeneral1:app_no and
          agqend:prem_no  = agqgeneral1:prem_no and
          agqend:build_no = agqgeneral1:build_no
        begin
        if agqend:lob_end_code one of "P" then
            begin
            writefile(l_dec,"%s","<033>&a100h+0V")
            writefile(l_dec,"%s",trun(l_arial))
            writefile(l_dec,"%s",trun(agqend:form_edition))
            writefile(l_dec,"%s","<033>&a1600h+0V")
            writefile(l_dec,"%s",trun(agqend:description))
            if agqend:premium <> 0 then 
                begin
                writefile(l_dec,"%s","<033>&a4200h+0V")
                writefile(l_dec,"%s",str(agqend:premium,"ZZZ,ZZZ.99-"))
                end
            else
            if agqend:manual_premium <> 0 then
                begin
                writefile(l_dec,"%s","<033>&a4200h+0V")
                writefile(l_dec,"%s",str(agqend:manual_premium,"ZZZ,ZZZ.99-"))
                end
            writefile(l_dec,"%s","<NL>")
            end

        next agqend
        end
           
    next agqgeneral1
    end

access agqbusiness, set agqbusiness:app_no = agqprint1:app_no, generic

while agqbusiness:app_no = agqprint1:app_no
    begin
    access agqgeneral1, set agqgeneral1:app_no = agqbusiness:app_no,
                           agqgeneral1:prem_no  = agqbusiness:prem_no,
                           agqgeneral1:build_no = agqbusiness:build_no, generic

    l_form = agqbusiness:form
    access sfsform, set sfsform:company_id       = agqname:company_id,
                        sfsform:state            = l_state,
                        sfsform:line_of_business = l_lob,
                        sfsform:policy_form      = l_form, generic

    l_risk_type = agqbusiness:risk_type
    l_coverage  = agqbusiness:coverage
    access cpsbusrisktypes, set cpsbusrisktypes:company_id       = agqname:company_id,
                                cpsbusrisktypes:state            = l_state,
                                cpsbusrisktypes:line_of_business = l_lob,
                                cpsbusrisktypes:risk_type        = l_risk_type, generic

    access cpsbuscovtypes, set cpsbuscovtypes:company_id       = agqname:company_id,
                               cpsbuscovtypes:state            = l_state,
                               cpsbuscovtypes:line_of_business = l_lob,
                               cpsbuscovtypes:coverage         = l_coverage, generic

    l_recovery_set = agqbusiness:recovery_set
    access cpsbusrecoveryset, set cpsbusrecoveryset:company_id       = agqname:company_id,
                                  cpsbusrecoveryset:state            = l_state,
                                  cpsbusrecoveryset:line_of_business = l_lob,
                                  cpsbusrecoveryset:recovery_set     = l_recovery_set, generic

    if agqbusiness:limit <> 0 then
        begin
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s%s","Location:  ",str(agqbusiness:prem_no,"ZZZZ"))
        writefile(l_dec,"%s","<033>&a1200h+0V")
        writefile(l_dec,"%s%s","Building:  ",str(agqbusiness:build_no,"ZZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s%s%s%s","Form: ",str(agqbusiness:form),
                                 " ",
                                 trun(sfsform:description))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s%s%s%s","Coverage: ",agqbusiness:coverage," ",cpsbuscovtypes:description)
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s%s","Limit:     ",str(agqbusiness:limit,"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<NL>")
        if agqbusiness:coverage one of "D", "D1" then
            begin
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s%s%s","Risk Type: ",agqbusiness:risk_type," ",cpsbusrisktypes:description)
            writefile(l_dec,"%s","<033>&a1500h+0V")
            writefile(l_dec,"%s","Apartment/Condo: ")
            switch(agqbusiness:apartment_condo)
              case 1  : writefile(l_dec,"%s","Yes")
              default : writefile(l_dec,"%s","No")
              end
            writefile(l_dec,"%s","<033>&a2800h+0V")
            writefile(l_dec,"%s%s%s","Coinsurance: ",str(agqbusiness:coinsurance),"%")
            end
        else
            begin
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s","Recovery Set: ",str(agqbusiness:recovery_set))
            writefile(l_dec,"%s","<033>&a1100h+0V")
            writefile(l_dec,"%s",cpsbusrecoveryset:description)
            end
           
        if agqbusiness:dependent_property = 1 then
            begin
            l_code = "CPQ301"
            access agqendorse5, set agqendorse5:app_no = agqbusiness:app_no,
                                   agqendorse5:prem_no  = agqbusiness:prem_no,
                                   agqendorse5:build_no = agqbusiness:build_no,
                                   agqendorse5:code     = l_code, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
	    if agqendorse5:option[1] = 1 then
                writefile(l_dec,"%s","Dependent Property - CP1508")
            else
                writefile(l_dec,"%s","Dependent Property - CP1509")
            end
	if agqbusiness:agreed_value = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Agreed Value")
            end
	if agqbusiness:premium_adjustment = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Premium Adjustment")
            end
        if agqbusiness:Electronic_media = 1 then
            begin
            access agqelectmedia, set agqelectmedia:app_no = agqbusiness:app_no,
                                      agqelectmedia:prem_no  = agqbusiness:prem_no,
                                      agqelectmedia:build_no = agqbusiness:build_no, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
	    if agqelectmedia:no_limit = 1 then
                writefile(l_dec,"%s","Electronic Media - No Limit")
            else
                writefile(l_dec,"%s","Electronic Media - 180 Days")
            end
        if agqbusiness:extended_period_indemnity = 1 then
            begin
            access agqextperiod, set agqextperiod:app_no = agqbusiness:app_no,
                                     agqextperiod:prem_no  = agqbusiness:prem_no,
                                     agqextperiod:build_no = agqbusiness:build_no, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s%s","Extended Period of Indemnity - ",str(agqextperiod:no_days)," Days")
            end
	if agqbusiness:max_recovery_period = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Maximum Period of Indemnity")
            end
        if agqbusiness:monthly_recovery_limitation = 1 then
            begin
            l_code = "CPQ304"
            access agqendorse5, set agqendorse5:app_no = agqbusiness:app_no,
                                   agqendorse5:prem_no  = agqbusiness:prem_no,
                                   agqendorse5:build_no = agqbusiness:build_no,
                                   agqendorse5:code     = l_code, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s","Monthly Limit - ",str(agqendorse5:monthly_percent))
            end
	if agqbusiness:mining_property = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Mining Properities")
            end
        if agqbusiness:payroll_limitation = 1 then
            begin
            access agqbuspayroll, set agqbuspayroll:app_no = agqbusiness:app_no,
                                      agqbuspayroll:prem_no  = agqbusiness:prem_no,
                                      agqbuspayroll:build_no = agqbusiness:build_no, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s%s","Ordinary Payroll - ",str(agqbuspayroll:no_days)," Days")
            end
	if agqbusiness:heat_power_refrig = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Power, Heat & Refrigeration")
            end
	if agqbusiness:seasonal_leases = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Seasonal Leases")
            end
        if agqbusiness:loss_tuition_fees = 1 then
            begin
            l_code = "CPQ305"
            access agqendorse5, set agqendorse5:app_no = agqbusiness:app_no,
                                   agqendorse5:prem_no  = agqbusiness:prem_no,
                                   agqendorse5:build_no = agqbusiness:build_no,
                                   agqendorse5:code     = l_code, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s","Loss Tuition - ",str(agqendorse5:coinsurance,"ZZZ%"))
            end
	if agqbusiness:building_law = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Ordinance or Law")
            end
        if agqbusiness:utility = 1 then
            begin
            l_code = "CPQ308"
            access agqendorse5, set agqendorse5:app_no = agqbusiness:app_no,
                                   agqendorse5:prem_no  = agqbusiness:prem_no,
                                   agqendorse5:build_no = agqbusiness:build_no,
                                   agqendorse5:code     = l_code, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            if agqendorse5:option1[1] = 1 then
                begin 
                writefile(l_dec,"%s","Utility Services - Power Equipment - Public")
                writefile(l_dec,"%s","<NL>")
                end 
            if agqendorse5:option1[2] = 1 then
                begin 
                writefile(l_dec,"%s","Utility Services - Water Supply - Public")
                writefile(l_dec,"%s","<NL>")
                end 
            if agqendorse5:option1[3] = 1 then
                begin 
                writefile(l_dec,"%s","Utility Services - Communication Services - Public")
                writefile(l_dec,"%s","<NL>")
                end 
            if agqendorse5:option1[4] = 1 then
                begin 
                writefile(l_dec,"%s","Utility Services - Power Transmission - Public")
                writefile(l_dec,"%s","<NL>")
                end 
            if agqendorse5:option1[5] = 1 then
                begin 
                writefile(l_dec,"%s","Utility Services - Communication Lines - Public")
                writefile(l_dec,"%s","<NL>")
                end 
            end
	if agqbusiness:loss_adjustment = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Loss Adjustment")
            end
        if agqbusiness:time_period = 1 then
            begin
            l_code = "CPQ307"
            access agqendorse5, set agqendorse5:app_no = agqbusiness:app_no,
                                   agqendorse5:prem_no  = agqbusiness:prem_no,
                                   agqendorse5:build_no = agqbusiness:build_no,
                                   agqendorse5:code     = l_code, generic
 
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            if agqendorse5:option[1] = 1 then
                writefile(l_dec,"%s","Time Period - 24 Hour")
            else
                writefile(l_dec,"%s","Time Period - No Wait")
            end
	if agqbusiness:civil_authority = 1 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Civil Authority")
            end
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s","Rate")
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s","Adj Rate")
        writefile(l_dec,"%s","<033>&a2350h+0V")
        writefile(l_dec,"%s","Limit")
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s","Premium")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Group I")
        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqbusiness:bi_factor[1],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",str(agqbusiness:base_rate[1],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a2200h+0V")
        writefile(l_dec,"%s",str(agqbusiness:limit divide 100,"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s",str(agqbusiness:bi_premium[1],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Group II")
        writefile(l_dec,"%s","<033>&a1100h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqbusiness:bi_factor[2],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",str(agqbusiness:base_rate[2],"ZZ.999"))
        writefile(l_dec,"%s","<033>&a2200h+0V")
        writefile(l_dec,"%s",str(agqbusiness:limit divide 100,"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s",str(agqbusiness:bi_premium[2],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")

        if agqgeneral1:form > 1 then
            begin
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s",trun(l_arial))
            switch(agqgeneral1:form)
              case 2 : writefile(l_dec,"%s","Broad")
              case 3 : writefile(l_dec,"%s","Special")
              end
            writefile(l_dec,"%s","<033>&a1100h+0V")
            writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
            writefile(l_dec,"%s",str(agqbusiness:bi_factor[3],"ZZ.999"))
            writefile(l_dec,"%s","<033>&a1650h+0V")
            writefile(l_dec,"%s",str(agqbusiness:base_rate[3],"ZZ.999"))
            writefile(l_dec,"%s","<033>&a2200h+0V")
            writefile(l_dec,"%s",str(agqbusiness:limit divide 100,"ZZZ,ZZZ,ZZZ"))
            writefile(l_dec,"%s","<033>&a2900h+0V")
            writefile(l_dec,"%s",str(agqbusiness:bi_premium[3],"ZZZ,ZZZ.99"))
            writefile(l_dec,"%s","<NL>")
            end

        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a1650h+0V")
        writefile(l_dec,"%s",trun(l_arial))
        writefile(l_dec,"%s","Total Premium")
        writefile(l_dec,"%s","<033>&a2900h+0V")
        writefile(l_dec,"%s",trun(l_letter_gothic_bold_10))
        writefile(l_dec,"%s",str(agqbusiness:bi_premium[1] +
                                 agqbusiness:bi_premium[2] +
                                 agqbusiness:bi_premium[3],"ZZZ,ZZZ.99"))

        access agqend, set agqend:app_no = agqbusiness:app_no,  
                           agqend:prem_no  = agqbusiness:prem_no, 
                           agqend:build_no = agqbusiness:build_no, generic
	
        l_business_income = "N"
	while agqend:app_no = agqbusiness:app_no and
              agqend:prem_no  = agqbusiness:prem_no and
              agqend:build_no = agqbusiness:build_no 
            begin  
	    if agqend:lob_end_code = "B" then
                l_business_income = "Y"

	    next agqend
            end 

	if l_business_income = "Y" then 
            begin
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
            end

        access agqend, set agqend:app_no = agqbusiness:app_no,  
                           agqend:prem_no  = agqbusiness:prem_no, 
                           agqend:build_no = agqbusiness:build_no, generic
	
        while agqend:app_no = agqbusiness:app_no and
              agqend:prem_no  = agqbusiness:prem_no and
              agqend:build_no = agqbusiness:build_no
            begin
            if agqend:lob_end_code one of "B" then 
                begin
                writefile(l_dec,"%s","<033>&a300h+0V")
                writefile(l_dec,"%s",trun(l_arial))
                writefile(l_dec,"%s",trun(agqend:form_edition))
                writefile(l_dec,"%s","<033>&a1600h+0V")
                writefile(l_dec,"%s",trun(agqend:description))
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
           
        end

    next agqbusiness
    end
