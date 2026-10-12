# Write your MySQL query statement below
select  CASE 
            when id%2=1 AND id+1 IN (select id from seat ) then id+1
            when id%2=0 then id-1
            else id
        END
as id, student from seat
order by id;