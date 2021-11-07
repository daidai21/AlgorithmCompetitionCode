-- https://www.nowcoder.com/discuss/781465?type=2&order=3&pos=21&page=1&source_id=discuss_tag_nctrack&channel=-1&gio_id=6F5D4EE42240A854387E6C6A910640EC-1636218920502
--   id, stu_id, course, score
-- .
-- .
-- .
-- .
-- 查询各科成绩都大于90的学生姓名
-- id      name    course  score
-- 1       小白      语文      91
-- 2       小白      数学      88
-- 3       小黑      语文      79
-- 4       小黑      数学      92
-- 5       小花      语文      99
-- 6       小花      数学      95
-- 7       小花      英语      96
-- .
-- .
-- .
-- .
CREATE TABLE `test` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(32) DEFAULT NULL ,
    `course` varchar(32) DEFAULT NULL,
    `score` int(11) DEFAULT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB AUTO_INCREMENT = 8 DEFAULT CHARSET = utf8;

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('1', '小白', '语文', '91');

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('2', '小白', '数学', '88');

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('3', '小黑', '语文', '79');

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('4', '小黑', '数学', '92');

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('5', '小花', '语文', '99');

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('6', '小花', '数学', '95');

insert into
    `test` (`id`, `name`, `course`, `score`)
values
    ('7', '小花', '英语', '96');


select * from test;

-- not in
select distinct name 
from test 
where name not in (
    select name
    from test
    where score <= 90
)
;

-- having
select distinct name
from test
group by name
having min(score) > 90
;

