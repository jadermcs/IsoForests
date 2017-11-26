import csv

file_w = open('../dirty_deputies.txt', 'w')

check =  lambda x: False if x == '' else True

with open('../dirty_deputies_v2.csv', encoding = "UTF-8") as lines:
     dr = csv.DictReader(lines)

     for data in dr:
         if (check(data['deputy_name']) and check(data['deputy_state']) and
        check(data['political_party']) and check(data['refund_description']) and
            check(data['company_name']) and check(data['company_id']) and
            check(data['refund_date']) and check(data['refund_value'])):

             line = data['deputy_name'] + '|' + data['deputy_state'] + '|' + \
                data['political_party'] + '|' + data['refund_description'] + '|' + \
                data['company_name'] + '|' + data['company_id'] + '|' + \
                data['refund_date'] + '|' + data['refund_value'] + '\n'
             file_w.write(line)

file_w.close()
