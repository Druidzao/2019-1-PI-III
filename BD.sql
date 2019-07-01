create database Assistencia;
use Assistencia;

create table funcionario(
p_codigo int auto_increment not null,
nome varchar(50) not null,
funcao varchar(20) not null,
primary key (p_codigo)
);

create table aparelho(
p_codigo int auto_increment not null,
nome varchar(20) not null,
marca varchar(20) not null,
modelo varchar(20),
serie character(20),
primary key (p_codigo)
);

create table produto(
p_codigo int auto_increment not null,
nome varchar(34) not null,
quantidade smallint not null,
valor decimal(15,2) not null,
primary key (p_codigo)
);

create table cliente(
p_codigo int auto_increment not null,
nome varchar(50) not null,
endereco varchar(255),
telefone varchar(17),
celular varchar(17),
primary key (p_codigo)
);

create table ordem_servico(
p_codigo int auto_increment not null,
data_abertura date not null,
data_fechamento date,
sts char not null,
defeito_reclamado varchar(255) not null,
observacao varchar(255),
laudo varchar(255), 
vlr_mo decimal(15,2),
vlr_total decimal(15,2),
f_funcionario int not null,
f_aparelho int not null,
f_cliente int not null,
primary key (p_codigo),
constraint fk_ordem_servico_funcionario foreign key (f_funcionario) references funcionario(p_codigo),
constraint fk_ordem_servico_aparelho foreign key (f_aparelho) references aparelho(p_codigo),
constraint fk_ordem_servico_cliente foreign key (f_cliente) references cliente(p_codigo)
);

create table item_servico(
quantidade smallint,
valor decimal(15,2),
f_produto int not null,
f_ordem_servico int not null,
constraint fk_item_produto foreign key (f_produto) references produto(p_codigo),
constraint fk_item_servico foreign key (f_ordem_servico) references ordem_servico(p_codigo)
);