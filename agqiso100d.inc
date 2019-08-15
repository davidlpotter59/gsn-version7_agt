/* agqiso100d.inc

   scips.com

   april 11, 2006

   inland worksheet
*/

writefile(l_dec,"%s",trun(l_arial))
if agqinland:app_no = agqprint1:app_no then
    begin
    writefile(l_dec,"%s","<033>&a2000h+0V")
    writefile(l_dec,"%s","INLAND MARINE")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")
    end

while agqinland:app_no = agqprint1:app_no
    Begin
    access agqlocation, set agqlocation:app_no = agqinland:app_no,
                            agqlocation:prem_no  = agqinland:prem_no,
                            agqlocation:build_no = agqinland:build_no, generic

    l_state             = agqinland:state
    l_county            = agqinland:county
    l_lob               = agqinland:rating_line_of_business

    access sfsstate, set sfsstate:company_id = agqname:company_id,
                         sfsstate:state      = l_state,
                         sfsstate:county     = "00", generic

    access sfsstate_alias, set sfsstate_alias:company_id = agqname:company_id,
                               sfsstate_alias:state      = l_state,
                               sfsstate_alias:county     = l_county, generic

    writefile(l_dec,"%s",trun(l_arial))
    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s","Location:  ",str(agqinland:prem_no,"ZZZZ"))
    writefile(l_dec,"%s","<033>&a1000h+0V")
    writefile(l_dec,"%s%s","Building:  ",str(agqinland:build_no,"ZZZZ"))
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
                               trun(agqinland:business_description[1]),
                               " ",
                               trun(agqinland:business_description[2]))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    writefile(l_dec,"%s","<033>&a300h+0V")
    writefile(l_dec,"%s%s%s%s","State:  ",str(agqinland:state)," ",trun(sfsstate:description))
    writefile(l_dec,"%s","<033>&a2300h+0V")
    writefile(l_dec,"%s%s%s%s","County:  ",str(agqinland:county)," ",trun(sfsstate_alias:description))
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")

    if agqinland:option[1] = 1 then
        begin
        l_code = "CM0066"
        access agqendorse6, set agqendorse6:app_no = agqinland:app_no,
                                agqendorse6:prem_no  = agqinland:prem_no,
                                agqendorse6:build_no = agqinland:build_no, 
                                agqendorse6:code     = l_code, generic

        l_class_code        = agqendorse6:class_code
        l_duplicate_records = agqendorse6:duplicate_records
        l_receptacles       = agqendorse6:receptacles

        access cpsimduprecords, set cpsimduprecords:company_id       = agqname:company_id,
                                    cpsimduprecords:state            = l_state,
                                    cpsimduprecords:line_of_business = l_lob,
                                    cpsimduprecords:class_code       = l_class_code,
                                    cpsimduprecords:duplicate_record = l_duplicate_records, generic

        access cpsimreceptacle, set cpsimreceptacle:company_id       = agqname:company_id,
                                    cpsimreceptacle:state            = l_state,
                                    cpsimreceptacle:line_of_business = l_lob,
                                    cpsimreceptacle:class_code       = l_class_code,
                                    cpsimreceptacle:receptacles      = l_receptacles, generic

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Accounts Receivable")
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s%s","Class Code - ",str(agqendorse6:class_code))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        switch(agqendorse6:nonreporting)
          case 1  : writefile(l_dec,"%s","Non-Reporting")
          default : writefile(l_dec,"%s","Reporting")
          end
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Classification Of Risk:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        switch(agqendorse6:class_of_risk)
          case 1  : writefile(l_dec,"%s","Yes")
          default : writefile(l_dec,"%s","No")
          end
        If agqendorse6:class_of_risk = 1 then
          {
            writefile(l_dec,"%s","<033>&a1700h+0V")
            writefile(l_dec,"%s","(Wholesalers, manufacturers or insurance agents if at least 51% of the covered")
            writefile(l_dec,"%s","<033>&a1700h+120V")
            writefile(l_dec,"%s","Accounts Receivable are so classified)")
          }


        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Coinsurance:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:coinsurance[1],"ZZZ%"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Duplicate Records:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s%s%s",str(agqendorse6:duplicate_records)," - ",
                                 trun(cpsimduprecords:description))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Receptacles:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s%s%s",str(agqendorse6:receptacles)," - ",
                                 trun(cpsimreceptacle:description))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Base")
        writefile(l_dec,"%s","<033>&a1000h+0V")
       writefile(l_dec,"%s","Reporting")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","Coins")
        writefile(l_dec,"%s","<033>&a2400h+0V")
        writefile(l_dec,"%s","Receptacles")
        writefile(l_dec,"%s","<033>&a3100h+0V")
        writefile(l_dec,"%s","Duplicate")
        writefile(l_dec,"%s","<033>&a3800h+0V")
        writefile(l_dec,"%s","Class")
        writefile(l_dec,"%s","<033>&a4300h+0V")
        writefile(l_dec,"%s","RMF")
        writefile(l_dec,"%s","<033>&a4700h+0V")
        writefile(l_dec,"%s","Exposure")
        writefile(l_dec,"%s","<033>&a5200h+0V")
        writefile(l_dec,"%s","Premium")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Rate")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","  Type")
        writefile(l_dec,"%s","<033>&a3100h+0V")
        writefile(l_dec,"%s"," Records")
        writefile(l_dec,"%s","<033>&a3800h+0V")
        writefile(l_dec,"%s","Risk")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:base_rate[1],"9.999"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s",str(agqendorse6:nonreporting_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:coinsurance_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a2400h+0V")
        writefile(l_dec,"%s",str(agqendorse6:receptacle_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a3100h+0V")
        writefile(l_dec,"%s",str(agqendorse6:duplicate_records,"9.999"))
        writefile(l_dec,"%s","<033>&a3800h+0V")
        Writefile(l_dec,"%s",str(agqendorse6:class_risk_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a4300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:rmf,"9.999"))
        writefile(l_dec,"%s","<033>&a4700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[1],"ZZZZZZZZ"))
        writefile(l_dec,"%s","<033>&a5100h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[1],"ZZZ,ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Property")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","RMF")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","Premium")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","  Away")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:property_away_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s",str(agqendorse6:rmf,"9.999"))
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[2],"ZZZ,ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Total Premium:")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[3],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","LC/LCM: ")
        writefile(l_dec,"%s","<033>&a1450h+0V")
        writefile(l_dec,"%s",str(agqendorse6:ar_factor *
                                 agqendorse6:loss_cost,"Z.ZZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Final Premium: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:total_premium,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        Writefile(l_dec,"%s","<NL>")
        end

    if agqinland:option[3] = 1 then
        begin
        l_code = "CM0020"
        access agqendorse6, set agqendorse6:app_no = agqinland:app_no,
                                agqendorse6:prem_no  = agqinland:prem_no,
                                agqendorse6:build_no = agqinland:build_no, 
                                agqendorse6:code     = l_code, generic

        l_class_code        = agqendorse6:class_code
        l_duplicate_records = agqendorse6:duplicate_records
        l_receptacles       = agqendorse6:receptacles

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Commercial Articles")
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s%s","Class Code - ",str(agqendorse6:class_code))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s",agqendorse6:class_description)
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s%s","Deductible: ",str(agqendorse6:deductible[1],"ZZZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s%s","Limit:  ",str(agqendorse6:limit[1],"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","  Limit")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","Rate")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","  Premium")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[2],"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
        Writefile(l_dec,"%s",str(agqendorse6:base_rate[1]))
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[1],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[3],"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
	if agqendorse6:base_rate[2] <> 0 then
            writefile(l_dec,"%s",str(agqendorse6:base_rate[2]))
        writefile(l_dec,"%s","<033>&a1700h+0V")
	if agqendorse6:premium[2] <> 0 then
            begin 
            writefile(l_dec,"%s",str(agqendorse6:premium[2],"ZZZ,ZZZ.99"))
            writefile(l_dec,"%s","<NL>")
            end
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Premium:")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[3],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Deductible Factor:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:deductible_factor))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","RMF: ")
        writefile(l_dec,"%s","<033>&a1450h+0V")
        writefile(l_dec,"%s",str(agqendorse6:rmf))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Final Premium: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:total_premium,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")
        end

    if agqinland:option[9] = 1 then
        begin
        l_code = "CM0026"
        access agqendorse6, set agqendorse6:app_no = agqinland:app_no,
                                agqendorse6:prem_no  = agqinland:prem_no,
                                agqendorse6:build_no = agqinland:build_no, 
                                agqendorse6:code     = l_code, generic

        l_class_code        = agqendorse6:class_code
        l_duplicate_records = agqendorse6:duplicate_records
        l_receptacles       = agqendorse6:receptacles

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Physicians & Surgeons")
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s%s","Class Code - ",str(agqendorse6:class_code))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        Writefile(l_dec,"%s","Deductible: ")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:deductible[1],"ZZZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Limit: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[1],"ZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Rate: ")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:base_rate[1]))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Premium: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:total_premium,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")
        end

    if agqinland:option[10] = 1 then
        begin
        l_code = "CM0028"
        access agqendorse6, set agqendorse6:app_no = agqinland:app_no,
                                agqendorse6:prem_no  = agqinland:prem_no,
                                agqendorse6:build_no = agqinland:build_no, 
                                agqendorse6:code     = l_code, generic

        l_class_code        = agqendorse6:class_code
        l_duplicate_records = agqendorse6:duplicate_records
        l_receptacles       = agqendorse6:receptacles

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Signs")
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s%s","Class Code - ",str(agqendorse6:class_code))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Limit: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[1],"ZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Inside Signs: ")
        if agqendorse6:inside_outside_signs = "I" then
            writefile(l_dec,"%s","X")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s","Outside Signs: ")
        if agqendorse6:inside_outside_signs = "O" then
            writefile(l_dec,"%s","X")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Full Coverage: ")
        if agqendorse6:full_partial_coverage = 1 then
            writefile(l_dec,"%s","X")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s","5% of Limit: ")
        if agqendorse6:full_partial_coverage = 2 then
            writefile(l_dec,"%s","X")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","  Limit")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","Rate")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","  Premium")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[2],"ZZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
        Writefile(l_dec,"%s",str(agqendorse6:base_rate[1]))
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[1],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Premium:")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[3],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","RMF: ")
        writefile(l_dec,"%s","<033>&a1450h+0V")
        writefile(l_dec,"%s",str(agqendorse6:rmf))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Final Premium: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:total_premium,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        Writefile(l_dec,"%s","<NL>")
        end

    if agqinland:option[12] = 1 then
        begin
        l_code = "CM0067"
        access agqendorse6, set agqendorse6:app_no = agqinland:app_no,
                                agqendorse6:prem_no  = agqinland:prem_no,
                                agqendorse6:build_no = agqinland:build_no, 
                                agqendorse6:code     = l_code, generic

        l_class_code        = agqendorse6:class_code
        l_duplicate_records = agqendorse6:duplicate_records
        l_receptacles       = agqendorse6:receptacles

        access cpsimduprecords, set cpsimduprecords:company_id       = agqname:company_id,
                                    cpsimduprecords:state            = l_state,
                                    cpsimduprecords:line_of_business = l_lob,
                                    cpsimduprecords:class_code       = l_class_code,
                                    cpsimduprecords:duplicate_record = l_duplicate_records, generic

        access cpsimreceptacle, set cpsimreceptacle:company_id       = agqname:company_id,
                                    cpsimreceptacle:state            = l_state,
                                    cpsimreceptacle:line_of_business = l_lob,
                                    cpsimreceptacle:class_code       = l_class_code,
                                    cpsimreceptacle:receptacles      = l_receptacles, generic

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Valuable Papers")
        writefile(l_dec,"%s","<033>&a2300h+0V")
        writefile(l_dec,"%s%s","Class Code - ",str(agqendorse6:class_code))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Deductible:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:deductible[1],"ZZZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Limit:")
        writefile(l_dec,"%s","<033>&a1400h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[1],"ZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Property Away Limit:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:limit[2],"ZZ,ZZZ,ZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Unscheduled:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
	if agqendorse6:nonreporting = 1 then
            writefile(l_dec,"%s","X")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Coinsurance:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s",str(agqendorse6:coinsurance[1],"ZZZ%"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Receptacles:")
        writefile(l_dec,"%s","<033>&a1500h+0V")
        writefile(l_dec,"%s%s%s",str(agqendorse6:receptacles)," - ",
                                 trun(cpsimreceptacle:description))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Base")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","Schedule")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","Coins")
        writefile(l_dec,"%s","<033>&a2400h+0V")
        writefile(l_dec,"%s","Container")
        writefile(l_dec,"%s","<033>&a3100h+0V")
        writefile(l_dec,"%s","Deductible")
        writefile(l_dec,"%s","<033>&a3800h+0V")
        writefile(l_dec,"%s","RMF")
        writefile(l_dec,"%s","<033>&a4300h+0V")
        writefile(l_dec,"%s","Premium")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Rate")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","Factor")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","Factor")
        writefile(l_dec,"%s","<033>&a3100h+0V")
        writefile(l_dec,"%s","Factor")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:base_rate[1],"9.999"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s",str(agqendorse6:nonreporting_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:coinsurance_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a2400h+0V")
        writefile(l_dec,"%s",str(agqendorse6:receptacle_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a3100h+0V")
        writefile(l_dec,"%s",str(agqendorse6:deductible_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a3800h+0V")
        writefile(l_dec,"%s",str(agqendorse6:rmf,"9.999"))
        writefile(l_dec,"%s","<033>&a4300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[1],"ZZZ,ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Property")
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s","RMF")
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s","Premium")
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","  Away")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:property_away_factor,"9.999"))
        writefile(l_dec,"%s","<033>&a1000h+0V")
        writefile(l_dec,"%s",str(agqendorse6:rmf,"9.999"))
        writefile(l_dec,"%s","<033>&a1700h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[2],"ZZZ,ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<NL>")

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Total Premium:")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:premium[3],"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","LC/LCM: ")
        writefile(l_dec,"%s","<033>&a1450h+0V")
        writefile(l_dec,"%s",str(agqendorse6:valuable_factor *
                                 agqendorse6:loss_cost,"Z.ZZZZ"))
        writefile(l_dec,"%s","<NL>")
        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s","Final Premium: ")
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",str(agqendorse6:total_premium,"ZZZ,ZZZ.99"))
        writefile(l_dec,"%s","<NL>")
        Writefile(l_dec,"%s","<NL>")
        end

    access agqend, set agqend:app_no = agqinland:app_no,
                       agqend:prem_no  = agqinland:prem_no,
                       agqend:build_no = agqinland:build_no, generic

    if agqend:app_no = agqinland:app_no and
       agqend:prem_no = agqinland:prem_no and
       agqend:build_no = agqinland:build_no then
      begin
            writefile(l_dec,"%s","<033>&a90h+0V")
            writefile(l_dec,"%s","Form/Edition")
            writefile(l_dec,"%s","<033>&a1090h+0V")
            writefile(l_dec,"%s","Description")
            writefile(l_dec,"%s","<033>&a3150h+0V")
            writefile(l_dec,"%s","Limit")
            writefile(l_dec,"%s","<033>&a3850h+0V")
            writefile(l_dec,"%s","Deductible")
            writefile(l_dec,"%s","<033>&a4550h+0V")
            writefile(l_dec,"%s","Rate")
            writefile(l_dec,"%s","<033>&a5100h+0V")
            writefile(l_dec,"%s","Premium")
            writefile(l_dec,"%s","<NL>")
        end

    access agqend, set agqend:app_no = agqinland:app_no,
                       agqend:prem_no  = agqinland:prem_no,
                       agqend:build_no = agqinland:build_no, generic
    
    while agqend:app_no = agqinland:app_no and
          agqend:prem_no = agqinland:prem_no and
          agqend:build_no = agqinland:build_no
    begin
      if agqend:lob_end_code one of "I" then
         begin
           writefile(l_dec,"%s","<033>&a90h+0V")
           writefile(l_dec,"%s",trun(agqend:form_edition))
           writefile(l_dec,"%s","<033>&a1090h+0V")
           writefile(l_dec,"%s",trun(agqend:description))
           writefile(l_dec,"%s","<033>&a3150h+0V")
           writefile(l_dec,"%s",str(agqend:limit,"$$$,$$$"))
           writefile(l_dec,"%s","<033>&a3850h+0V")
           writefile(l_dec,"%s",str(agqend:deductible,"ZZZZZ"))
           writefile(l_dec,"%s","<033>&a4500h+0V")
           writefile(l_dec,"%s",str(agqend:rate,"ZZZ.ZZZ"))
           If agqend:premium <> 0 then
             {
               writefile(l_dec,"%s","<033>&a5100h+0V")
               writefile(l_dec,"%s",str(agqend:premium,"$$$,$$$.99"))
             }
           else 
           if agqend:manual_premium <> 0 then
             begin
               writefile(l_dec,"%s","<033>&a5100h+0V")
               writefile(l_dec,"%s",str(agqend:manual_premium,"ZZZ,ZZZ.99-"))
             end

           writefile(l_dec,"%s","<NL>")
         end

	next agqend
        end
         
    next agqinland
    end
