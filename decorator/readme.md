1. 介绍     

Decorator Pattern，装饰模式，也叫做包装模式，是结构型模式的一种。装饰模式动态的给一个对象增加了额外的功能，并且这种扩充功能的方式对客户是透明的。装饰模式的具体实现就是把一些功能封装在一个个单独的子类中，并让这些子类包含要被装饰的对象，当有需要功能扩充的时候，客户就可以有选择的通过装饰类来装饰某个对象。装饰模式可以理解为继承的一种替代，他比继承更加灵活，客户可以根据需要自由选择。装饰模式利用装饰者持有一个组件对象的引用，并实现组件接口，通常会在其方法中调用组件对象的方法。实现一直链式调用的能力。       


主要组成部分
组件接口（Component）：定义一个接口，供具体组件和装饰者实现。这个接口通常包含一个或多个方法，供客户端调用。
具体组件（ConcreteComponent）：实现组件接口的具体对象。它是被装饰的对象，提供基本的功能。
装饰者（Decorator）：持有一个组件对象的引用，并实现组件接口，通常会在其方法中调用组件对象的方法。
具体装饰者（ConcreteDecorator）：扩展装饰者的功能，添加新的行为。



2. 应用场景     


需要组合多个功能的场景，避免类的膨胀：    
    当对象的功能需要组合时，装饰模式提供了一种灵活的方式来实现这些组合，而不需要修改现有的类。当有许多功能组合的可能性时，使用装饰模式可以避免创建大量的子类。比如，饮料的不同配料组合，收费不同。
    
需要动态添加功能的场景，遵循开闭原则：    
    当需要在运行时为对象添加额外功能时，装饰模式是一个很好的选择。装饰模式可以通过添加新的装饰者来实现，而不需要修改现有的代码。游戏角色在装备不同的武器道具时，攻击会附加不同的效果，且外观也会发生变化。    


3. 优缺点
优点：

灵活性：装饰模式允许在运行时动态地增加对象的功能，而不需要修改对象的结构。这使得功能的添加和组合变得更加灵活。

可扩展性：可以通过添加新的装饰者类来扩展功能，避免了类的膨胀。每个装饰者都可以独立开发和维护。

组合性：可以通过组合多个装饰者来创建复杂的功能，而不需要创建大量的子类。这种组合方式使得代码更整洁，易于理解。

遵循单一职责原则：装饰者和具体组件各自负责不同的功能，符合单一职责原则，使得代码更加模块化。

缺点：

复杂性：使用装饰模式可能会导致代码结构变得复杂，尤其是在装饰者层次较多时，可能会让理解和调试变得困难。
装饰者数量：如果不加控制，可能会出现过度装饰的情况，导致对象的功能变得难以理解或者过于复杂。
性能开销：每个装饰者都增加了一层间接调用，可能会导致性能开销，尤其是在装饰链较长时。











