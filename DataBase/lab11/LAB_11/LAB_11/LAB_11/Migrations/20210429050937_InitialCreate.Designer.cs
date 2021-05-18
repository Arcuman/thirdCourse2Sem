﻿// <auto-generated />
using System;
using LAB_11.Contexts;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

namespace LAB_11.Migrations
{
    [DbContext(typeof(AppDbContext))]
    [Migration("20210429050937_InitialCreate")]
    partial class InitialCreate
    {
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "5.0.5");

            modelBuilder.Entity("LAB_11.Models.Client", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<string>("Client_Name")
                        .HasColumnType("TEXT");

                    b.Property<string>("Phone_Number")
                        .HasColumnType("TEXT");

                    b.HasKey("Id");

                    b.ToTable("Clients");
                });

            modelBuilder.Entity("LAB_11.Models.Order", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<int>("ClientId")
                        .HasColumnType("INTEGER");

                    b.Property<DateTime>("Order_Date")
                        .HasColumnType("TEXT");

                    b.Property<DateTime>("Provision_Date")
                        .HasColumnType("TEXT");

                    b.Property<int>("Serviceid")
                        .HasColumnType("INTEGER");

                    b.HasKey("Id");

                    b.HasIndex("ClientId");

                    b.HasIndex("Serviceid");

                    b.ToTable("Orders");
                });

            modelBuilder.Entity("LAB_11.Models.Service", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("INTEGER");

                    b.Property<double>("Price")
                        .HasColumnType("REAL");

                    b.Property<string>("Service_Description")
                        .HasColumnType("TEXT");

                    b.Property<string>("Service_Name")
                        .HasColumnType("TEXT");

                    b.HasKey("Id");

                    b.ToTable("Services");
                });

            modelBuilder.Entity("LAB_11.Models.Order", b =>
                {
                    b.HasOne("LAB_11.Models.Client", "Client")
                        .WithMany("Orders")
                        .HasForeignKey("ClientId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.HasOne("LAB_11.Models.Service", "Service")
                        .WithMany("Orders")
                        .HasForeignKey("Serviceid")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Client");

                    b.Navigation("Service");
                });

            modelBuilder.Entity("LAB_11.Models.Client", b =>
                {
                    b.Navigation("Orders");
                });

            modelBuilder.Entity("LAB_11.Models.Service", b =>
                {
                    b.Navigation("Orders");
                });
#pragma warning restore 612, 618
        }
    }
}
