

1. 简介

Bulider Pattern，建造者模式，也叫做生成器模式，是一种对象创建型模式。建造者模式用于创建具有多个部件的复合对象，并隐藏了复合对象的创建过程，不同的部件建造者（Builder生成器）有不同的建造方法。建造者模式通过将对象的构建过程与表示分离，使得同样的构建过程可以创建不同的表示。      


建造者模式中的4种角色：

抽象建造者角色Builder：为建造各个组件提供统一的抽象接口；
具体建造者角色ConcreteBuilder：实现抽象建造者提供的抽象接口，定义各个组件的建造方法，是组件建造的具体实施者；
指挥者Director：调用具体建造者来建造产品的各个组件，指挥者并不知道产品的具体信息，指挥者只负责规定并保证各个组件的建造过程和建造逻辑（指挥建造的过程，比如先装发动机再装轮子）；
产品角色Product：被建造的复杂对象，包含组合对象的各个部件；


2. 适用场景

构建复杂对象：当对象由多个部件组成，且构建和组合过程复杂时，例如游戏中的角色（如怪物、NPC）。
产品变体多样化：当需要创建多种不同类型的产品，但构建过程相似时，例如不同类型的车辆（轿车、卡车、摩托车）。
构建过程需要控制：当构建过程需要明确的步骤和顺序时，例如根据不同条件动态调整构建顺序。
对象的构建与表示分离：当产品的构建与表示需要解耦，以便于后续维护和扩展，例如构建复杂文档时。
逐步构建对象：当对象的构建过程需要分步进行，或在构建过程中进行条件判断时，例如配置复杂系统。
需要灵活的对象创建：当需要在运行时决定构建哪种类型的对象时，例如根据用户输入或配置文件动态选择不同的构建器。


3. 优缺点

优点：

解耦：建造者模式将复杂对象的构建与表示分离，使得构建过程与产品的表示相互独立，降低了模块间的耦合度。
灵活性：可以通过更换具体建造者来灵活地构建不同类型的产品，而无需修改指挥者或客户端代码。
可读性和可维护性：通过清晰的接口和结构，增加了代码的可读性，便于后续的维护和扩展。
支持复杂对象的构建：适合构建复杂对象，特别是那些具有多个部件和装配顺序要求的对象。
步骤控制：指挥者可以控制构建的步骤和顺序，确保复杂对象按照预期的方式构建。
缺点：

复杂性：对于简单对象的构建，使用建造者模式可能显得过于复杂，增加了不必要的代码和结构。
类的数量增加：需要创建多个具体建造者类和产品类，可能导致类的数量增加，增加了系统的复杂性。
构建过程固定：一旦定义了指挥者的构建过程，可能不够灵活，难以适应一些动态变化的需求。
 
